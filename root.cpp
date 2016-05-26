#include<iostream>

#include "TGraph.h"   //pour ROOT
#include "TFile.h"
#include "TCanvas.h"
#include "TApplication.h"
#include <TROOT.h>
#include <TH1.h>
#include <TFile.h>
#include <TRandom.h>

using namespace std;

int main(int argc, char **argv)
{  
  
  TApplication theApp("App", &argc, argv);  
  
  TMultiGraph *histo = new TMultiGraph ();//permet de générer plusieurs courbe sur un même graph
  
  recuit(n,k,P)->Fill (x);
  
  TFile outfile (“histo.root”, “RECREATE”);
  
  TFile *fichiergraphique=TFile::Open("histo.root", "RECREATE");
  TGraph *histo=new TGraph(x);
  
  histo->SetLineColor(2);
  histo->SetMarkerColor(2);
  histo->SetMarkerStyle(20);
 
  histo->Write();

  TCanvas *c=new TCanvas();
  histo->Draw("APL");
  
  c->Update();
  c->SaveAs("histogramme.png");
  outfile.Close();
  
  // Affichage des figures si mode interactif (pas en mode batch)
  if(!gROOT->IsBatch()) theApp.Run();       

  return 0;
}
