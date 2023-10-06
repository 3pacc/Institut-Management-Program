#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
struct mat{
	int numm;
	char nomm[20];
};
struct prof {
	int nump;
	char nomp[10];
   char prenp[10];
};

struct etud {
	int nume;
	char nome[20];
   char	prene[20];
	
};
struct niv {
	mat *tm;
	etud *te;
	int nm;
	int ne;
};
struct etab{
	prof *tp;
	int np;
	niv tn[5];
};

void MENU_PRINCIPALE()
{
	system("cls");
	printf("\n");
	printf("\t\t\t\t\t      GESTION D'ECOLE");
	printf("\n");
	printf(" \n\t\t\t\t\t     1 _ MENU PROFESSEUR\t\n\t\t\t\t\t     2 _ MENU NIVEAU\t\n\t\t\t\t\t     3 _ QUITTER    ");
	printf(" \n\n\t\t\t\t\t    -->votre choix:");
}
void MENU_NIVEAU()
{
	system("cls");
	printf("\n");
	printf("\t\t\t\t\t         MENU NIVEAU");printf("\n");
	printf(" \n\t\t\t\t\t     1 _ MENU ETUDIANT\t\n\t\t\t\t\t     2 _ MENU MATIERE\t\n\t\t\t\t\t     3 _ RETOUR\t");printf("\n");
	printf(" \n\n\t\t\t\t\t    -->votre choix:");

	
}
void MENU_MATIERE()
{
	system("cls");
	printf("\n");
	printf("\t\t\t\t\t      MENU matiere");
	printf("\n");
	printf(" \n\t\t\t\t\t  1 _ AJOUTER\t\t\n\t\t\t\t\t  2 _ SUPPRIMER\t\t\n\t\t\t\t\t  3 _ MODIFIER\t\t\n\t\t\t\t\t  4 _ LISTER\t\t\n\t\t\t\t\t  5 _RETOUR\t\t");
	printf("\n");
	printf(" \n\t\t\t\t\t  -->votre choix:");
}
void MENU_ETUD()
{
	system("cls");
	printf("\n");
	printf("\t\t\t\t\t     MENU ETUDIANT");
	printf("\n");
	printf(" \n\t\t\t\t\t  1 _ AJOUTER\t\t\n\t\t\t\t\t  2 _ SUPPRIMER\t\t\n\t\t\t\t\t  3 _ MODIFIER\t\t\n\t\t\t\t\t  4 _ LISTER\t\t\n\t\t\t\t\t  5 _ RETOUR\t\t");
	printf(" \n\t\t\t\t\t  -->votre choix:");

	
}
void MENU_PROF()
{
	system("cls");
	printf("\n");
	printf("\t\t\t\t\t\tMENU PROF ");
	printf("\n");
    printf(" \n\t\t\t\t\t  1 _ AJOUTER\t\t\n\t\t\t\t\t  2 _ SUPPRIMER\t\t\n\t\t\t\t\t  3 _ MODIFIER\t\t\n\t\t\t\t\t  4 _ LISTER\t\t\n\t\t\t\t\t  5 _ RETOUR\t\t");
    printf("\n");
	printf(" \n\t\t\t\t\t  -->votre choix:");
}
void MENU_NIVEAU2()
{
	system("cls");
	printf("\n");
	printf("\t\t\t\t\t     MENU NIVEAU");
	printf("\n");
	printf(" \n\t\t\t\t\t  1 _ 1er annee\t\n\t\t\t\t\t  2 _ 2eme annee\t\n\t\t\t\t\t  3 _ 3eme annee\t\n\t\t\t\t\t  4 _ 4eme annee\t\n\t\t\t\t\t  5 _ 5eme annee\t");
	printf("\n");
	printf(" \n\t\t\t\t\t  -->votre choix:");
}

int unim(etab *e,int num)
{
	int i,j;
	for(j=0;j<5;j++)
	{
		for(i=0;i<e->tn[j].nm;i++)
		{
			if(e->tn[j].tm[i].numm==num)
			{
				return 1;
			}
			
		}
	}
	
	return 0;
}
void ajouterMatieres(etab *&e,int choixniv)
{
	int n; 
	if(e->tn[choixniv-1].nm==0)
	{
	   e->tn[choixniv-1].tm=(mat*)malloc(sizeof(mat));	
	}
	else
	{
		realloc(e->tn[choixniv-1].tm,sizeof(mat)*(e->tn[choixniv-1].nm+1));
	
	}
		printf("veuillez saisir un nom: ");
		scanf("%s",e->tn[choixniv-1].tm[e->tn[choixniv-1].nm].nomm);
		do
		{
			printf("veuillez saisir un num: ");
			scanf("%d",&e->tn[choixniv-1].tm[e->tn[choixniv-1].nm].numm);
			n=unim(e,e->tn[choixniv-1].tm[e->tn[choixniv-1].nm].numm);
		}while(n==1);
		e->tn[choixniv-1].nm++;		
	
}
int unie(etab *e,int num)
{
	int i,j;
	for(j=0;j<5;j++)
	{
		for(i=0;i<e->tn[j].ne;i++)
		{
			if(e->tn[j].te[i].nume==num)
			{
				return 1;
			}
			
		}
	}
	
	return 0;
}
void ajouterEtudiant(etab *&e,int choixniv)
{
	int n;
	if(e->tn[choixniv-1].ne==0)
	{
	  e->tn[choixniv-1].te=(etud*)malloc(sizeof(etud));
	
	}
	else
	{
		realloc(e->tn[choixniv-1].te,sizeof(etud)*((e->tn[choixniv-1].ne)+1));
	}
		printf("veuillez saisir un nom: ");
		scanf("%s",e->tn[choixniv-1].te[e->tn[choixniv-1].ne].nome);
		printf("veuillez donner un prenom:");
		scanf("%s",e->tn[choixniv-1].te[e->tn[choixniv-1].ne].prene);
		
		do
		{
			printf("veuillez saisir un num: ");
			scanf("%d",&e->tn[choixniv-1].te[e->tn[choixniv-1].ne].nume);
			n=unie(e,e->tn[choixniv-1].te[e->tn[choixniv-1].ne].nume);
		}while(n==1);
		
		e->tn[choixniv-1].ne++;		

}
int unip(etab *e,int num)
{
	int i;

		for(i=0;i<e->np;i++)
		{
			if(e->tp[i].nump==num)
			{
				return 1;
			}
			
		}
	
	
	return 0;
}

void ajouterProf(etab *&e)
{  
   int n;
    if(e->np==0)
	{
		e->tp=(prof*)malloc(sizeof(prof));
	}
	else
	{
		realloc(e->tp,sizeof(prof)*(e->np+1));
	}
		printf("veuillez saisir un nom: ");
		scanf("%s",e->tp[e->np].nomp);
		printf("veuiller saisir un prenom:");
    	scanf("%s",e->tp[e->np].prenp);
		do
		{
			printf("veuillez saisir un num ");
			scanf("%d",&e->tp[e->np].nump);
			n=unip(e,e->tp[e->np].nump);
		}while(n==1);
		
		e->np++;		
	
}
void supprimerProf(etab *&e)
{
	int i,j,num;
	if(e->np==0)
	{
		printf("Tableau vide on peut pas supprimer ");getch();
	
	}
	else
	{
		printf("veuillez saisir un numero pour supprimer");
		scanf("%d",&num);
		for( i=0;i<e->np;i++)
		{
			if(e->tp[i].nump==num)
			{
				for(j=i;j<e->np;j++)
				{
					e->tp[j]=e->tp[j+1];
				}
				printf("prof bien supprime \n");getch();
				e->np--;
			}
		}		
	}
}
void supprimerEtudiant(etab *&e,int choixniv)
{
	int i,j,num;
	if(e->tn[choixniv-1].ne==0)
	{
		printf("Tableau vide on peut pas supprimer ");getch();
	
	}
	else
	{
		printf("veuillez saisir un numero pour supprimer");
		scanf("%d",&num);
		for(i=0;i<e->tn[choixniv-1].ne;i++)
		{
			if(e->tn[choixniv-1].te[i].nume==num)
			{
				for(j=i;j<e->tn[choixniv-1].ne;j++)
				{
					e->tn[choixniv-1].te[j]=e->tn[choixniv-1].te[j+1];
				}
				printf("etudiant bien supprime \n");getch();
				e->tn[choixniv-1].ne--;
			}
		}		
	}
}
void supprimerMatieres(etab *&e,int choixniv)
{
	int i,j,num;
	if(e->tn[choixniv-1].nm==0)
	{
		printf("Tableau vide on peut pas supprimer ");getch();
	
	}
	else
	{
		printf("veuillez saisir un numero pour supprimer");
		scanf("%d",&num);
		for(i=0;i<e->tn[choixniv-1].nm;i++)
		{
			if(e->tn[choixniv-1].tm[i].numm==num)
			{
				for(j=i;j<e->tn[choixniv-1].nm;j++)
				{
					e->tn[choixniv-1].tm[j]=e->tn[choixniv-1].tm[j+1];
					
				}
				
				printf("etudiant bien supprime \n");getch();
				e->tn[choixniv-1].nm--;
			}
		}		
	}
}

void modifierEtudiant(etab *&e,int choixniv)
{
	int i,num,n;
	if(e->tn[choixniv-1].ne==0)
	{
		printf("Tableau vide on peut pas modifier ");getch();
	
	}
	else
	{
		printf("veuillez saisir un numero pour modifier");
		scanf("%d",&num);
		for(i=0;i<e->tn[choixniv-1].ne;i++)
		{
			if(e->tn[choixniv-1].te[i].nume==num)
			{
					printf("veuillez saisir un nom: ");
					scanf("%s",e->tn[choixniv-1].te[i].nome);
					printf("veuillez saisir un prenom: ");
					scanf("%s",e->tn[choixniv-1].te[i].prene);
			        printf("veuillez saisir un num: ");
			    	scanf("%d",&e->tn[choixniv-1].te[i].nume);
			 printf("etudiant bien Modifier \n");getch();
				i=e->tn[choixniv-1].ne;
			}
			
		}		
	}
}




void modifierProf(etab *&e)
{
	int i,num;
	if(e->np==0)
	{
		printf("Tableau vide on peut pas modifier ");getch();
	
	}
	else
	{
		printf("veuillez saisir le numero pour modifier");
		scanf("%d",&num);
		for(i=0;i<e->np;i++)
		{
			if(e->tp[i].nump==num)
			{
					printf("veuillez saisir un nom: ");
					scanf("%s",e->tp[i].nomp);
					printf("veuillez saisir un prenom: ");
					scanf("%s",e->tp[i].prenp);
					printf("veuillez saisir un num: ");
					scanf("%d",&e->tp[i].nump);
					printf("prof bien Modifier \n");getch();
				i=e->np;
			}
			
		}		
	}
}
void modifierMatieres(etab *&e,int choixniv)
{
	int i,num;
	if(e->tn[choixniv-1].nm==0)
	{
		printf("Tableau vide on peut pas modifier ");getch();
	
	}
	else
	{
		printf("veuillez saisir un numero pour modifier");
		scanf("%d",&num);
		for(i=0;i<e->tn[choixniv-1].nm;i++)
		{
			if(e->tn[choixniv-1].tm[i].numm==num)
			{
					printf("veuillez saisir un nom ");
					scanf("%s",e->tn[choixniv-1].tm[i].nomm);
					printf("veuillez saisir un num ");
					scanf("%d",&e->tn[choixniv-1].tm[i].numm);
					printf("etudiant bien Modifier \n");getch();
				i=e->tn[choixniv-1].nm;
			}
			
		}		
	}
}

void listerProf(etab *e)
{
	int i;
	for(i=0;i<e->np;i++)
	{
		printf("  %s | %s | %d \n",e->tp[i].nomp,e->tp[i].prenp,e->tp[i].nump);
	}
	getch();
}
void listerEtudiant(etab *e,int choixniv)
{
	int i;
	for(i=0;i<e->tn[choixniv-1].ne;i++)
	{
		printf("%s | %s | %d \n",e->tn[choixniv-1].te[i].nome,e->tn[choixniv-1].te[i].prene,e->tn[choixniv-1].te[i].nume);
	}
	getch();
}
void listerMatieres(etab *e,int choixniv)
{
	int i;
	for(i=0;i<e->tn[choixniv-1].nm;i++)
	{
		printf("%s | %d \n",e->tn[choixniv-1].tm[i].nomm,e->tn[choixniv-1].tm[i].numm);
	}
	getch();
}

main() {
	 system("color 70");
	etab *e=NULL;
  	e=(etab*)malloc(sizeof(etab));
    e->tp=NULL;
    e->np=0; 
    
	
	
	int choix1,choix2,choix3,choix4,choix5,choixniv,choixsave,i;
	for(i=0;i<5;i++)
	{
		e->tn[i].te=NULL;
		e->tn[i].tm=NULL;
		e->tn[i].ne=0;
		e->tn[i].nm=0;
	}

	do
	{
		system("cls");
			MENU_PRINCIPALE();
			scanf("%d",&choix1);
		switch(choix1)
		{
			case 1:
					do
					{
						system("cls");
						MENU_PROF();
						scanf("%d",&choix2);
						switch(choix2)
						{
							case 1 : ajouterProf(e);
									 break;
							case 2 :supprimerProf(e);
									break;
							case 3 : modifierProf(e);
									break;				 
							case 4 : listerProf(e); 
									 break;	 
							default : break;
						}
				
					}while(choix2!=5);
					break;
			case 2: 
					do
					{
						system("cls");
						do
						{
							system("cls");
							MENU_NIVEAU2();
							scanf("%d",&choixniv);	
						}while(choixniv>5);
						system("cls");
						MENU_NIVEAU();
						scanf("%d",&choix3);
						
						
						switch(choix3)
						{
							case 1 : 
									do
									{
										system("cls");
										MENU_ETUD();
										scanf("%d",&choix4);
										switch(choix4)
										{
													case 1 : ajouterEtudiant(e,choixniv);
									 					break;
													case 2 :supprimerEtudiant(e,choixniv);
															break;
													case 3 : modifierEtudiant(e,choixniv);
															break;				 
													case 4 : listerEtudiant(e,choixniv); 
									 						break;
														 
												default : break;
										}
				
									}while(choix4!=5);
										
									 break;
							case 2 :
									do
									{
										system("cls");
										MENU_MATIERE();
										scanf("%d",&choix5);
										switch(choix5)
										{
													case 1 :ajouterMatieres(e,choixniv);
									 					break;
													case 2 :supprimerMatieres(e,choixniv);
															break;
													case 3 : modifierMatieres(e,choixniv);
															break;				 
													case 4 : listerMatieres(e,choixniv); 
									 						break;		 
												default : break;
										}
				
									}while(choix5!=5);
									break;
						
									 
							default : break;
						}
				
					}while(choix3!=3);
					
					
					break;
			
			case 3: printf("QUIITER");
					break;	
			default : break;				
		}
		
		
	} while(choix1!=3);
	free(e);
}
