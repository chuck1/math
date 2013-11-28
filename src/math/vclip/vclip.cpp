class face: public feature
{
	
};
class edge: public feature
{

};
class vertex: public feature
{

};



vclip::rc clip(edge* e, std::set<plane*>)
{
	// clip e against planes p
	
	vec2 l_(0,1);
	float l = 0;
	
	// make global
	//feature* N_[2] = {0,1};
	
	feature* N = 0;
	
	vec2 d;
	
	// for each plane
	for(int i = 0; i < num_p; ++i )
	{
		N = p[i].feature;
		
		d[0] = P[i].dist(t);
		d[1] = P[i].dist(h);

		if( d[0] < 0 && d[1] < 0 )
		{
			N[0] = N;
			N[1] = N;
			return vclip::rc::SIMPLY_EXCLUDED;
		}
		else if( d[0] < 0 )
		{
			l = d[0]/(d[0]-d[1]);
			
			if( l > l_[0] )
			{
				l_[0] = l;
				N_[0] = N;
				if( l_[0] > l_[1] ) return false;
			}
		}
		else if( d[1] < 0 )
		{
			l = d[0]/(d[0]-d[1]);
			
			if( l < l_[1] )
			{
				l_[1] = l;
				N_[1] = N;
				if( l_[0] > l_[1] ) return false;
			}
		}
		return true;
	}
}

int derivative_sign(face* f, edge* e, float l)
{
	float d = p->dist(e.at(l)) ;
	float s = sign(e->v.dot(f->n));
	
	if( d > 0 )
		return s;
	if( d < 0 )
		return -s;
}
int derivative_sign(vertex* v, edge* e, float l)
{
	return sign(e->v.dot(e->at(l) - v->v));
}
feature* post()
{
	float s = derivative_sign(p,e,l);
	if( N_[0] == NULL && s > 0 )
	{
		return N_[0];
	}
	else if( 
}
vclip::rc handleLocalMin(face* f, vertex* v)
{
	float dmax = -100000000;
	
	poly* pol = f->pol;
	
	for( int i = 0; i < pol->num_f; ++i )
	{
		face* f1 = pol->f[i];
		plane* p1 = f1->p;
		float d = p1->dist(v);
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
vclip::rc vvstate()
{
	int rc = vvstate(0,1);
	if( rc == vclip::rc::NEXT )
		return vvstate(1,0);
	return rc;
}
vclip::rc vvstate(int a,int b)
{
	vertex* v0 = x[a];
	vertex* v1 = x[b];
	
	plane* p0 = NULL;
	edge* e0 = NULL;
	
	// search for plane VP(v0,e0) that v1 violates
	for( e0 = v0->e; e0 < (v0->e + v0->num_e); ++e0 )
	{
		plane* p = e.vp(v0);
		float d = p->dist(v1);
		if( d > 0 )
		{
			p0 = p;
			break;
		}
	}
	
	if( p0 != NULL )
	{
		x[a] = e0;
		return vclip::rc::CONTINUE;
	}
	return vclip::rc::NEXT;
}
vclip::rc vestate(int a,int b)
{
	vertex* v = x[a];
	edge* e = x[b];
	
	face* f = NULL;
	face* f0 = NULL;
	plane* p0 = NULL;
	
	// search for plane VP(e,f) that v violates
	for( f = e->f; f < (e->f + e->f_num); ++f )
	{
		plane* p = e->vp(f);
		float d = p->dist(v);
		if( d > 0 )
		{
			f0 = f;
			p0 = p;
			break;
		}
	}
	
	if( p0 != NULL )
	{
		x[b] = f0;
		return vclip::rc::CONTINUE;
	}
	
	clipEdge()
	if( N_[0] == NULL && N_[1] == NULL )
	{
		x[a] = NULL;
	}
	else
	{
		// check derivative
	}
	
	if( /* v changed */ )
	{
		return vclip::rc::CONTINUE;
	}
	return vclip::rc::DONE;
}
vclip::rc vfstate(int a,int b)
{
	vertex* v = x[a];
	face* f = x[b];
	
	edge* e = NULL;
	edge* e0 = NULL;
	float d0 = 0;
	// search for plane VP(f,e) that v maximally violates
	for( e = f->e; e < (f->e + f->num_e); ++e )
	{
		plane* p = vp(f,e);
		float d = p->dist(v);
		
		if( d < d0 )
		{
			d0 = d;
			e0 = e;
		}
	}
	
	if( e0 != NULL )
	{
		x[b] = e0;
		return vclip::rc::CONTINUE;
	}
	
	plane* p = f->p;
	
	// search for edge incident to v and v'
	// such that abs(d(p,v)) > abs(d(p,v'))
	d0 = p->dist(v0);
	e0 = NULL;
	for( e = v->e; e < (v->e + v->num_e); ++e )
	{
		d1 = p->dist(v1);
		
		if( abs(d0) > abs(d1) )
		{
			e0 = e;
		}
	}
	
	if( e0 != NULL )
	{
		x[a] = e0;
		return vclip::rc::CONTINUE;
	}
	
	if( d0 > 0 ) return vclip::rc::DONE;
	
	return handleLocalMin();
}
vclip::rc eestate()
{
	if( eestate(0,1) == vclip::rc::DONE )
		return eestate(1,0);
	
	return vclip::rc::DONE;
}
vclip::rc eestate(int a,int b)
{
	edge* e0 = x[a];
	edge* e1 = x[b];
	
	int rc = clip(e1, e0->ve);
	
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


