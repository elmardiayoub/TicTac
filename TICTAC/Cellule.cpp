#include "stdafx.h"
#include "Cellule.h"


void Cellule::dessiner(CDialogEx *dlg)
{


	//rc.TopLeft();
	//rc.BottomRight();
	// rc now contains the rectangle of your window!
	CPen stylo(PS_SOLID, 1, RGB(0, 0, 0));
	CClientDC dc(dlg);

	dc.SelectObject(&stylo);

	dc.Rectangle(this);

	state = 0;

}

void Cellule::rond(CDialogEx *dlg)
{
	if (!state)
	{
		CBrush b(RGB(0, 0, 128));
		CClientDC dc(dlg);
		dc.SelectObject(&b);
		dc.Ellipse(this);
	}
	state = -1;
}

void Cellule::croix(CDialogEx *dlg)
{
	if (!state)
	{
		CPen stylo(PS_SOLID, 2, RGB(255, 0, 0));
		CClientDC dc(dlg);
		dc.SelectObject(&stylo);

		dc.MoveTo(TopLeft());
		dc.LineTo(BottomRight());


		dc.MoveTo(right, top);
		dc.LineTo(left, bottom);
	}
	state = -1;

}

Cellule::Cellule()
{

	this->TopLeft()= CPoint(0, 0);
	this->BottomRight() = CPoint(50, 50) + CPoint(30,30);
	etat = '-';
}


Cellule::~Cellule()
{
}
