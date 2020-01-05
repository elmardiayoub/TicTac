#pragma once
#include"Cellule.h"
class grille
{
	Cellule grid[3][3];
public:

	void dessiner(CDialogEx*);
	void playerA(CPoint&, CDialogEx*);
	bool EstPartieGagne();
	void playerB(CPoint&, CDialogEx*);
	void at(CPoint&, int&, int&);
	grille();
	~grille();
};

