#ifndef __NEBULA_VCLIP_H__
#define __NEBULA_VCLIP_H__

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
			return 0.0;
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
		math::vec3	at(float l);
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
math::vec3	edge::at(float l)
{
	return h->v - t->v;
}



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
		rc		eestate(int,int);


		polyhedron*	poly_[2];

		feature*	x_[2];
		
		feature*	N_[2];
};

#endif
