#include <stdio.h>
#include <string.h>
#include "ajouter.h"
#include <gtk/gtk.h>
  

 void ajouter_agent(agent p)
{
 FILE *f; 
 f=fopen("agent.txt","a+");
 if(f!=NULL)
 {
 fprintf(f,"%s %s %s %s %s %s %s \n",p.nom,p.prenom,p.datenaiss,p.adresseemail,p.numtel,p.daterec,p.adresse);
 fclose(f);
}
}
void modifier_agent(agent p)
{
 FILE *f; 
 f=fopen("agent.txt","a+");
 if(f!=NULL)
 {
 fprintf(f,"%s %s %s %s %s %s %s \n",p.nom,p.prenom,p.datenaiss,p.adresseemail,p.numtel,p.daterec,p.adresse);
 fclose(f);
}
}
