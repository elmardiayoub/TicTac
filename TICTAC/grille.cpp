#include "stdafx.h"
#include "grille.h"


grille::grille()
{
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			grid[i][j].TopLeft() = CPoint((i + 1) * 80, 80 * (j + 1));
			grid[i][j].BottomRight() = grid[i][j].TopLeft() + CPoint(80, 80);
			grid[i][j].etat = '-';
		}
}


void grille::dessiner(CDialogEx *dlg)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			grid[i][j].dessiner(dlg);
}


void grille::playerA(CPoint& p, CDialogEx* dlg)
{
	int i, j;
	at(p, i, j);
	if ((i == -1) || (j == -1)) return;
	grid[i][j].croix(dlg);
	grid[i][j].etat = 'x';
	if (EstPartieGagne())
	{
		AfxMessageBox(_T("Player A win"));
		exit(-1);
	}
}

bool grille::EstPartieGagne()
{
	if (grid[0][0].etat == grid[0][1].etat && grid[0][0].etat == grid[0][2].etat && grid[0][0].etat != '-')		//Ligne 1 
		return  true;
	else if (grid[1][0].etat == grid[1][1].etat && grid[1][0].etat == grid[1][2].etat && grid[1][0].etat != '-') //Ligne 2 
		return  true;
	else if (grid[2][0].etat == grid[2][1].etat && grid[2][0].etat == grid[2][2].etat && grid[2][0].etat != '-') //Ligne 3 
		return  true;
	else if (grid[0][0].etat == grid[1][0].etat && grid[0][0].etat == grid[2][0].etat && grid[0][0].etat != '-') // colonne 1 
		return  true;
	else if (grid[0][1].etat == grid[1][1].etat && grid[0][1].etat == grid[2][1].etat && grid[0][1].etat != '-')  // colonne 2
		return  true;
	else if (grid[0][2].etat == grid[1][2].etat && grid[0][2].etat == grid[2][2].etat && grid[0][2].etat != '-')  // colonne 3 
		return  true;
	else if (grid[0][0].etat == grid[1][1].etat && grid[0][0].etat == grid[2][2].etat && grid[0][0].etat != '-') // Diagonale 1 
		return  true;
	else if (grid[0][2].etat == grid[1][1].etat && grid[0][2].etat == grid[2][0].etat && grid[0][2].etat != '-') // Diagonale 2 
		return  true;

	return false;

}

void grille::playerB(CPoint& p, CDialogEx* dlg)
{
	int i, j;
	at(p, i, j);
	if ((i == -1) || (j == -1)) return;
	grid[i][j].rond(dlg);
	grid[i][j].etat = 'o';
	if (EstPartieGagne())
	{
		
		AfxMessageBox(_T("Player B win"));
		exit(-1);
	}
}

void grille::at(CPoint & p, int & ix, int & jx)
{
	ix = jx = -1;
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j].PtInRect(p))
			{
				ix = i;
				jx = j;

				return;
			}

}

grille::~grille()
{

}
