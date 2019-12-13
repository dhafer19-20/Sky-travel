#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif


#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "ajouter.h"
#include "afficher.h"
#include "clientfid.h"

void
on_retour1acc_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *gestionagents, *accueil;
GtkWidget *image9;
GtkWidget *image10;
gestionagents=lookup_widget(button,"gestionagents");
gtk_widget_destroy(gestionagents);
accueil=create_accueil();
gtk_widget_show(accueil);
image9=lookup_widget(accueil,"image9");
gtk_image_set_from_file(GTK_IMAGE(image9),"/home/insaf/Pictures/m.jpg");
image10=lookup_widget(accueil,"image10");
gtk_image_set_from_file(GTK_IMAGE(image10),"/home/insaf/Pictures/n.jpg");
}


void
on_ajouterag_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
agent p;
GtkWidget *input1, *input2, *input3,*input4,*input5,*input6,*input7;

GtkWidget *gestionagents;
GtkWidget *msgaj;
GtkWidget *treeviewag;
gestionagents=lookup_widget(button,"gestionagents");
input1=lookup_widget(button,"entry1");
input2=lookup_widget(button,"entry2");
input3=lookup_widget(button,"entry3");
input4=lookup_widget(button,"entry4");
input5=lookup_widget(button,"entry5");
input6=lookup_widget(button,"entry6");
input7=lookup_widget(button,"entry7");


strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.datenaiss,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.adresseemail,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(p.numtel,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(p.daterec,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(p.adresse,gtk_entry_get_text(GTK_ENTRY(input7)));
ajouter_agent(p);

msgaj=create_msgaj();
gtk_widget_show(msgaj);
treeviewag=lookup_widget(gestionagents,"treeviewag");

afficher_agent(treeviewag);
}


void
on_treeviewag_row_activated             (GtkTreeView     *treeviewag,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar *NOM;
gchar *PRENOM;
gchar *DATENAISS;
gchar *ADRESSEEMAIL;
gchar *NUMTEL;
gchar *DATEREC;
gchar *ADRESSE;
GtkWidget *gestionagents;
GtkWidget *modifiersupprimer;
GtkTreeIter iter;
GtkWidget *nom;
GtkWidget *prenom;
GtkWidget *datenaiss;
GtkWidget *adresseemail;
GtkWidget *numtel;
GtkWidget *daterec;
GtkWidget *adresse;
GtkWidget *image6;
GtkWidget *image7;
GtkWidget *image8;
gestionagents=lookup_widget(treeviewag,"gestionagents");
gtk_widget_hide(gestionagents);
GtkTreeModel *model = gtk_tree_view_get_model(treeviewag);
if(gtk_tree_model_get_iter(model,&iter,path))
{gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&NOM,1,&PRENOM,2,&DATENAISS,3,&ADRESSEEMAIL,4,&NUMTEL,5,&DATEREC,6,&ADRESSE,-1);}
modifiersupprimer= create_modifiersupprimer();
nom=lookup_widget(modifiersupprimer,"nom");
prenom=lookup_widget(modifiersupprimer,"prenom");
datenaiss=lookup_widget(modifiersupprimer,"datenaiss");
adresseemail=lookup_widget(modifiersupprimer,"adresseemail");
numtel=lookup_widget(modifiersupprimer,"numtel");
daterec=lookup_widget(modifiersupprimer,"daterec");
adresse=lookup_widget(modifiersupprimer,"adresse");

    gtk_entry_set_text(GTK_ENTRY(nom),NOM);
    gtk_entry_set_text(GTK_ENTRY(prenom),PRENOM);
    gtk_entry_set_text(GTK_ENTRY(datenaiss),DATENAISS);	
    gtk_entry_set_text(GTK_ENTRY(adresseemail),ADRESSEEMAIL); 
    gtk_entry_set_text(GTK_ENTRY(numtel),NUMTEL); 
    gtk_entry_set_text(GTK_ENTRY(daterec),DATEREC);
    gtk_entry_set_text(GTK_ENTRY(adresse),ADRESSE);
 gtk_widget_show (modifiersupprimer);
image6=lookup_widget(modifiersupprimer,"image6");
gtk_image_set_from_file(GTK_IMAGE(image6),"/home/insaf/Pictures/m.jpg");
image7=lookup_widget(modifiersupprimer,"image7");
gtk_image_set_from_file(GTK_IMAGE(image7),"/home/insaf/Pictures/n.jpg");
image8=lookup_widget(modifiersupprimer,"image8");
gtk_image_set_from_file(GTK_IMAGE(image8),"/home/insaf/Pictures/téléchargement.jpg");
}


void
on_gestionagents_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *gestionagents;
GtkWidget *accueil;
GtkWidget *treeviewag;
GtkWidget *image3;
GtkWidget *image4;
GtkWidget *image1;
GtkWidget *image2;
GtkWidget *image5;

accueil=lookup_widget(button,"accueil");

gtk_widget_destroy(accueil);
gestionagents=lookup_widget(button,"gestionagents");

gestionagents=create_gestionagents();
gtk_widget_show(gestionagents);
image1=lookup_widget(gestionagents,"image1");
gtk_image_set_from_file(GTK_IMAGE(image1),"/home/insaf/Pictures/m.jpg");
image3=lookup_widget(gestionagents,"image3");
gtk_image_set_from_file(GTK_IMAGE(image3),"/home/insaf/Pictures/m.jpg");
image2=lookup_widget(gestionagents,"image2");
gtk_image_set_from_file(GTK_IMAGE(image2),"/home/insaf/Pictures/n.jpg");
image4=lookup_widget(gestionagents,"image4");
gtk_image_set_from_file(GTK_IMAGE(image4),"/home/insaf/Pictures/n.jpg");
image5=lookup_widget(gestionagents,"image5");
gtk_image_set_from_file(GTK_IMAGE(image5),"/home/insaf/Pictures/téléchargement.jpg");
treeviewag=lookup_widget(gestionagents,"treeviewag");

afficher_agent(treeviewag);
}


void
on_reclamations_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *accueil;
GtkWidget *reclamations;
GtkWidget *image11;
GtkWidget *image12;
accueil=lookup_widget(button,"accueil");
gtk_widget_hide(accueil);
reclamations= create_reclamations ();
gtk_widget_show (reclamations);
image11=lookup_widget(reclamations,"image11");
gtk_image_set_from_file(GTK_IMAGE(image11),"/home/insaf/Pictures/m.jpg");
image12=lookup_widget(reclamations,"image12");
gtk_image_set_from_file(GTK_IMAGE(image12),"/home/insaf/Pictures/n.jpg");
}


void
on_gestion_fidelites_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *accueil;
GtkWidget *gestionfidelites;
GtkWidget *image13;
GtkWidget *image14;
GtkWidget *image15;
GtkWidget *treeviewcf;
accueil=lookup_widget(button,"accueil");
gtk_widget_destroy(accueil);
gestionfidelites=lookup_widget(button,"gestionfidelites");
gestionfidelites= create_gestionfidelites ();
gtk_widget_show (gestionfidelites);
image13=lookup_widget(gestionfidelites,"image13");
gtk_image_set_from_file(GTK_IMAGE(image13),"/home/insaf/Pictures/m.jpg");
image14=lookup_widget(gestionfidelites,"image14");
gtk_image_set_from_file(GTK_IMAGE(image14),"/home/insaf/Pictures/n.jpg");
image15=lookup_widget(gestionfidelites,"image15");
gtk_image_set_from_file(GTK_IMAGE(image15),"/home/insaf/Pictures/fidele.jpg");
treeviewcf=lookup_widget(gestionfidelites,"treeviewcf");

afficher_clientfid(treeviewcf);
}


void
on_modifierag_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
char id [30];
 agent p;
GtkWidget *input8, *input9, *input10,*input11,*input12,*input13,*input14,*input;
GtkWidget *modifiersupprimer;
GtkWidget *msgmod;
FILE*f;
FILE*f2;
modifiersupprimer=lookup_widget(button,"modifiersupprimer");
input=lookup_widget(button,"nom");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
f=fopen("agent.txt","r");
f2=fopen("agent1.txt","a");
    if(f!=NULL)
 {
while(fscanf(f,"%s %s %s %s %s %s %s \n",p.nom,p.prenom,p.datenaiss,p.adresseemail,p.numtel,p.daterec,p.adresse)!=EOF)
     {
 if (strcmp(p.nom,id)!=0) 
  {
fprintf(f2,"%s %s %s %s %s %s %s \n",p.nom,p.prenom,p.datenaiss,p.adresseemail,p.numtel,p.daterec,p.adresse);
     }
 }
 fclose(f);
 fclose(f2);
}
remove("agent.txt");
rename("agent1.txt","agent.txt");

input8=lookup_widget(button,"nom");
input9=lookup_widget(button,"prenom");
input10=lookup_widget(button,"datenaiss");
input11=lookup_widget(button,"adresseemail");
input12=lookup_widget(button,"numtel");
input13=lookup_widget(button,"daterec");
input14=lookup_widget(button,"adresse");

strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input9)));
strcpy(p.datenaiss,gtk_entry_get_text(GTK_ENTRY(input10)));
strcpy(p.adresseemail,gtk_entry_get_text(GTK_ENTRY(input11)));
strcpy(p.numtel,gtk_entry_get_text(GTK_ENTRY(input12)));
strcpy(p.daterec,gtk_entry_get_text(GTK_ENTRY(input13)));
strcpy(p.adresse,gtk_entry_get_text(GTK_ENTRY(input14)));

modifier_agent(p);

msgmod=create_msgmod();
gtk_widget_show(msgmod);
}




void
on_supprimerag_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
char id [30];
agent p;
GtkWidget *modifiersupprimer;
GtkWidget *msgsupp;
GtkWidget *input;
FILE*f;
FILE*f3;
modifiersupprimer=lookup_widget(button,"modifiersupprimer");
input=lookup_widget(button,"nom");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
f=fopen("agent.txt","r");
f3=fopen("agent2.txt","a");
 while(fscanf(f,"%s %s %s %s %s %s %s \n",p.nom,p.prenom,p.datenaiss,p.adresseemail,p.numtel,p.daterec,p.adresse)!=EOF)
     {
if (strcmp(p.nom,id)!=0) 
    {
    fprintf(f3,"%s %s %s %s %s %s %s \n",p.nom,p.prenom,p.datenaiss,p.adresseemail,p.numtel,p.daterec,p.adresse);
     }
 }
 fclose(f);
 fclose(f3);
remove("agent.txt");
rename("agent2.txt","agent.txt");

msgsupp=create_msgsupp();
gtk_widget_show(msgsupp);
}


void
on_retour2acc_clicked                     (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *gestionagents, *modifiersupprimer, *treeviewag;
GtkWidget *image3;
GtkWidget *image4;
GtkWidget *image1;
GtkWidget *image2;
GtkWidget *image5;
modifiersupprimer=lookup_widget(button,"modifiersupprimer");
gtk_widget_destroy(modifiersupprimer);
gestionagents=create_gestionagents();
gtk_widget_show(gestionagents);
image1=lookup_widget(gestionagents,"image1");
gtk_image_set_from_file(GTK_IMAGE(image1),"/home/insaf/Pictures/m.jpg");
image3=lookup_widget(gestionagents,"image3");
gtk_image_set_from_file(GTK_IMAGE(image3),"/home/insaf/Pictures/m.jpg");
image2=lookup_widget(gestionagents,"image2");
gtk_image_set_from_file(GTK_IMAGE(image2),"/home/insaf/Pictures/n.jpg");
image4=lookup_widget(gestionagents,"image4");
gtk_image_set_from_file(GTK_IMAGE(image4),"/home/insaf/Pictures/n.jpg");
image5=lookup_widget(gestionagents,"image5");
gtk_image_set_from_file(GTK_IMAGE(image5),"/home/insaf/Pictures/téléchargement.jpg");
treeviewag=lookup_widget(gestionagents,"treeviewag");

afficher_agent(treeviewag);
}



void
on_retour3acc_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *reclamations, *accueil;
GtkWidget *image9;
GtkWidget *image10;
reclamations=lookup_widget(button,"reclamations");
gtk_widget_destroy(reclamations);
accueil=create_accueil();
gtk_widget_show(accueil);
image9=lookup_widget(accueil,"image9");
gtk_image_set_from_file(GTK_IMAGE(image9),"/home/insaf/Pictures/m.jpg");
image10=lookup_widget(accueil,"image10");
gtk_image_set_from_file(GTK_IMAGE(image10),"/home/insaf/Pictures/n.jpg");
}




void
on_treeviewcf_row_activated             (GtkTreeView     *treeviewcf,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar *NOM;
gchar *PRENOM;
gchar *DATENAISS;
gchar *ADRESSEEMAIL;
gchar *NUMTEL;
gchar *CODE;
GtkWidget *gestionfidelites;
GtkTreeIter iter;
GtkWidget *nom;
GtkWidget *prenom;
GtkWidget *datenaiss;
GtkWidget *adresseemail;
GtkWidget *numtel;
GtkWidget *code;

gestionfidelites=lookup_widget(treeviewcf,"gestionfidelites");
gtk_widget_show (gestionfidelites);
GtkTreeModel *model = gtk_tree_view_get_model(treeviewcf);
if(gtk_tree_model_get_iter(model,&iter,path))
{gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&NOM,1,&PRENOM,2,&DATENAISS,3,&ADRESSEEMAIL,4,&NUMTEL,5,&CODE,-1);}
nom=lookup_widget(gestionfidelites,"nomcl");
prenom=lookup_widget(gestionfidelites,"prenomcl");
datenaiss=lookup_widget(gestionfidelites,"datenaisscl");
adresseemail=lookup_widget(gestionfidelites,"adresseemailcl");
numtel=lookup_widget(gestionfidelites,"numtelcl");
code=lookup_widget(gestionfidelites,"codecl");

    gtk_entry_set_text(GTK_ENTRY(nom),NOM);
    gtk_entry_set_text(GTK_ENTRY(prenom),PRENOM);
    gtk_entry_set_text(GTK_ENTRY(datenaiss),DATENAISS);	
    gtk_entry_set_text(GTK_ENTRY(adresseemail),ADRESSEEMAIL); 
    gtk_entry_set_text(GTK_ENTRY(numtel),NUMTEL); 
    gtk_entry_set_text(GTK_ENTRY(code),CODE);
 

}




void
on_chercherag_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
char id [30];
agent p;
GtkWidget *gestionagents;
GtkWidget *input;
GtkWidget *treeviewag;
FILE*f;
FILE*f2;


gestionagents=lookup_widget(button,"gestionagents");
input=lookup_widget(button,"entrychercher");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
f=fopen("agent.txt","r");

 if(f!=NULL)
 {
  while(fscanf(f,"%s %s %s %s %s %s %s \n",p.nom,p.prenom,p.datenaiss,p.adresseemail,p.numtel,p.daterec,p.adresse)!=EOF)
     {
       f2=fopen("chercher.txt","a+");
       if  (f2!=NULL)
   {  
     
     if ((strcmp(p.nom,id)==0) || (strcmp(p.prenom,id)==0))
     { 
     fprintf(f2,"%s %s %s %s %s %s %s \n",p.nom,p.prenom,p.datenaiss,p.adresseemail,p.numtel,p.daterec,p.adresse);
     }
   
     treeviewag=lookup_widget(gestionagents,"treeviewag");
     chercher_agent(treeviewag);
    
        fclose(f2);
    }

 }
 fclose(f);
}
remove("chercher.txt");
}







void
on_envoyercode_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
}


void
on_retour4acc_clicked                  (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *gestionfidelites, *accueil;
GtkWidget *image9;
GtkWidget *image10;
gestionfidelites=lookup_widget(button,"gestionfidelites");
gtk_widget_destroy(gestionfidelites);
accueil=create_accueil();
gtk_widget_show(accueil);
image9=lookup_widget(accueil,"image9");
gtk_image_set_from_file(GTK_IMAGE(image9),"/home/insaf/Pictures/m.jpg");
image10=lookup_widget(accueil,"image10");
gtk_image_set_from_file(GTK_IMAGE(image10),"/home/insaf/Pictures/n.jpg");
}





