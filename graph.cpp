#include<iostream>
#include "TGraph.h"   //pour ROOT
#include "TFile.h"
#include "TCanvas.h"
#include "TApplication.h"
#include <TROOT.h>
#include <TH1.h>
#include <TFile.h>
#include <TRandom.h>
#include <vector>

using namespace std;

void graph (const int P[][2], vector <int> ordre (n),int argc, char **argv)
{
  TApplication theApp("App", &argc, argv);

  TH1F *histo = new TH1F (“histo”, “histogramme points”, n, -100.0, 100);
  TRandom rnd;
  for (int i = 0; i < 10000; ++i) {
    double x = rnd.Gaus (1.5, 1.0);
    histo->Fill (x);
  }
  TFile outfile (“histo.root”, “RECREATE”);

  TFile *fichiergraphique=TFile::Open("histo.root", "RECREATE");
  TGraph *histo=new TGraph(n);

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



}
