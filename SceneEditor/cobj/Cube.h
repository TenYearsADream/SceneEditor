//������
//���г����(l, w, h)��������

#pragma once
#include "Obj.h"
class CCube :
	public CObj
{
public:
	CCube();
	CCube(istream& file);
	~CCube();
	void draw();
	void mark();
	friend ostream& operator<<(ostream& out, CCube cube);
};
