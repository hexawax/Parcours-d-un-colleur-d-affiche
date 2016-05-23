#ifndef _GRAPH_H_
#define _GRAPH_H_
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
#include "recuit.h"
#include "PM.h"

void graph (const int P[][2], vector <int> ordre);// ,int argc, char **argv);
#endif
