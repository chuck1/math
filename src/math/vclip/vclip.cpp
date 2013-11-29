#include <stdlib.h>
#include <set>

#include <math/vec2.h>
#include <math/vec3.h>

class feature;
class vertex;
class face;

class plane
{
	public:
		plane(feature* feat0,feature* feat1)
		{

		}
		float	dist(math::vec3 v)
		{
			
		}
		math::vec3 n;
};
class polyhedron
{
	public:
		std::set<face*>		f;
};
class feature
{
	public:
};
class face: public feature
{
	public:
		std::set<feature*>	e;
		plane			p;
};
class edge: public feature
{
	public:
		math::vec3	at(float l)
		{

		}
		vertex*		other(vertex*);
		

		math::vec3 u;
		vertex* t;
		vertex* h;
		face* f[2];
};
class vertex: public feature
{
	public:
		std::set<feature*>	e;
		math::vec3		v;
};

class vclip
{
	public:
		enum rc
		{
			SIMPLY_EXCLUDED,
			NOT_EXCLUDED,
			EXCLUDED,
			CONTINUE,
			PENETRATION,
			NEXT,
			DONE
		};



		rc		clip(edge* e, feature* feat0, std::set<feature*> feats);
		feature*	post(face* f, edge* e, float l);
		rc 		handleLocalMin(int a, face* f, vertex* v);
		rc		vvstate();
		rc		vvstate(int,int);
		rc		vestate(int,int);
		rc		vfstate(int,int);
		rc		eestate();


		polyhedron*	poly_[2];

		feature*	x_[2];
		
		feature*	N_[2];
};


vclip::rc vclip::clip(edge* e, feature* feat0, std::set<feature*> feats)
{
	// clip e against planes p

	math::vec2 l_(0,1);
	float l = 0;

	// make global
	feature* N_[2] = {0,0};

	feature* N = 0;

	math::vec2 d;

	// for each plane
	for( auto it = feats.begin(); it != feats.end(); ++it )
	{
		feature* feat1 = *it;

		plane p(feat0, feat1);

		d.x = p.dist(e->t->v);
		d.y = p.dist(e->h->v);

		if( d.x < 0 && d.y < 0 )
		{
			N_[0] = feat1;
			N_[1] = feat1;
			return vclip::rc::SIMPLY_EXCLUDED;
		}
		else if( d.x < 0 )
		{
			l = d.x/(d.x-d.y);

			if( l > l_.x )
			{
				l_.x = l;
				N_[0] = N;
				if( l_.x > l_.y ) return vclip::rc::EXCLUDED;
			}
		}
		else if( d.y < 0 )
		{
			l = d.x/(d.x-d.y);

			if( l < l_.y )
			{
				l_.y = l;
				N_[1] = N;
				if( l_.x > l_.y ) return vclip::rc::EXCLUDED;
			}
		}
		return vclip::rc::NOT_EXCLUDED;
	}
}
int derivative_sign(face* f, edge* e, float l)
{
	float d = f->p.dist(e->at(l)) ;
	float s = ( e->u.dot(f->p.n) ) > 0 ? 1 : -1;

	if( d > 0 )
		return s;
	if( d < 0 )
		return -s;
}
int derivative_sign(vertex* v, edge* e, float l)
{
	return (e->u.dot(e->at(l) - v->v)) > 0 ? 1 : -1;
}
feature* vclip::post(face* f, edge* e, float l)
{	
	float s = derivative_sign(f,e,l);
	if( N_[0] == NULL && s > 0 )
	{
		return N_[0];
	}
	else if(1) 
	{
	}
}
vclip::rc vclip::handleLocalMin(int a, face* f, vertex* v)
{
	float dmax = -100000000;

	polyhedron* pol = poly_[a];

	face* f0 = NULL;

	for( auto it = pol->f.begin(); it != pol->f.end(); ++it )
	{
		face* f1 = *it;

		plane* p1 = &f1->p;
		float d = p1->dist(v->v);
		if( d > dmax )
		{
			dmax = d;
			f0 = f1;
		}
	}

	if( dmax <= 0 ) return vclip::rc::PENETRATION;

	f = f0;
	return vclip::rc::CONTINUE;
}
vclip::rc vclip::vvstate()
{
	vclip::rc rc = vvstate(0,1);
	if( rc == vclip::rc::NEXT )
		return vvstate(1,0);
	return rc;
}
vclip::rc vclip::vvstate(int a,int b)
{
	vertex* v0 = (vertex*)x_[a];
	vertex* v1 = (vertex*)x_[b];

	plane* p0 = NULL;
	edge* e0 = NULL;
	edge* e0__ = NULL;
	
	// search for plane VP(v0,e0) that v1 violates
	for( auto it = v0->e.begin(); it != v0->e.end(); ++it )
	{
		edge* e0 = (edge*)(*it);
		
		plane p(e0,v0);
		
		float d = p.dist(v1->v);
		
		if( d > 0 )
		{
			e0__ = e0;
			break;
		}
	}
	
	if( e0__ != NULL )
	{
		x_[a] = e0__;
		return vclip::rc::CONTINUE;
	}
	return vclip::rc::NEXT;
}
vclip::rc vclip::vestate(int a,int b)
{
	vertex* v = (vertex*)x_[a];
	edge* e = (edge*)x_[b];

	face* f = NULL;
	face* f0 = NULL;
	plane* p0 = NULL;

	// search for plane VP(e,f) that v violates
	for( int i = 0; i < 2; ++i )
	{
		f = e->f[i];
		
		plane p(e,f);
		
		float d = p.dist(v->v);
		if( d > 0 )
		{
			f0 = f;
			break;
		}
	}

	if( f0 != NULL )
	{
		x_[b] = f0;
		return vclip::rc::CONTINUE;
	}
	
	
	clip(e,v,v->e);
	
	if( N_[0] == NULL && N_[1] == NULL )
	{
		x_[a] = NULL;
	}
	else
	{
		// check derivative
	}

	if( 1 /* v changed */ )
	{
		return vclip::rc::CONTINUE;
	}
	return vclip::rc::DONE;
}
vclip::rc vclip::vfstate(int a,int b)
{
	vertex* v = (vertex*)x_[a];
	face* f = (face*)x_[b];

	edge* e = NULL;
	edge* e0 = NULL;
	float d0 = 0;
	// search for plane VP(f,e) that v maximally violates
	for( auto it = f->e.begin(); it != f->e.end(); ++it )
	{
		e = (edge*)(*it);
		
		plane p(f,e);
		float d = p.dist(v->v);

		if( d < d0 )
		{
			d0 = d;
			e0 = e;
		}
	}

	if( e0 != NULL )
	{
		x_[b] = e0;
		return vclip::rc::CONTINUE;
	}

	plane p = f->p;

	// search for edge incident to v and v'
	// such that abs(d(p,v)) > abs(d(p,v'))
	d0 = p.dist(v->v);
	float d1;
	e0 = NULL;
	for( auto it = v->e.begin(); it != v->e.end(); ++it )
	{
		e = (edge*)(*it);
		vertex* v1 = e->other(v);
	
		d1 = p.dist(v1->v);

		if( abs(d0) > abs(d1) )
		{
			e0 = e;
			x_[a] = e0;
			return vclip::rc::CONTINUE;
		}
	}
	if( d0 > 0 ) return vclip::rc::DONE;

	return handleLocalMin(b,f,v);
}
vclip::rc vclip::eestate()
{
	if( eestate(0,1) == vclip::rc::DONE )
		return eestate(1,0);

	return vclip::rc::DONE;
}
vclip::rc vclip::eestate(int a,int b)
{
	edge* e0 = x[a];
	edge* e1 = x[b];

	int rc = clip(e1, e0, e0->v);

	if( rc == vclip::rc::SIMPLY_EXCLUDED)
	{
		x[b] = v;
	}
	else
	{
		derivate_check();
	}

	// if e1 was updated
	if( x[b] != e1 )
	{
		return vclip::rc::CONTINUE;
	}

	rc = clip(e1, e0->fe);
	if( rc == vclip::rc::SIMPLY_EXCLUDED)
	{
		x[b] = f;
	}
	else
	{
		derivate_check();
	}

	// if e1 was updated
	if( x[b] != e1 )
	{
		return vclip::rc::CONTINUE;
	}

	return vclip::rc::DONE;	
}


