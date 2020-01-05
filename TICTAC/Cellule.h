#pragma once
class Cellule:public CRect
{
private:
	int state = 0;
public:	char etat;
public :
	void dessiner(CDialogEx*);
	void rond(CDialogEx*);
	void croix(CDialogEx*);
public:
	Cellule();
	~Cellule();
};

