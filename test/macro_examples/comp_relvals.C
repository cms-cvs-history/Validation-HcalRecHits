// Commands executed in a GLOBAL scope, e.g. created hitograms aren't erased...
{

      
   TFile f1("HcalRecHitsValidationALL_RelVal_210pre9_startup.root");
   TFile f2("HcalRecHitsValidationALL_RelVal_210pre9_ideal.root");
   
   // service variables
   //
   const int Nhist1  = 16; 
   const int Nhist2  = 1;
   const int Nhist2p = Nhist2; // profile hist analogous to 2D
   const int Nprof   = 16;

   TH1F* f1_hist1[Nhist1];
   TH1F* f2_hist1[Nhist1];

   TH2F*     f1_hist2[Nhist2];
   TH2F*     f2_hist2[Nhist2];

   TProfile* f1_histp[Nhist2p];
   TProfile* f2_histp[Nhist2p];

   TProfile* f1_prof[Nprof];
   TProfile* f2_prof[Nprof];

   TH1D* fp1[Nprof];
   TH1D* fp2[Nprof];

   char *label1[Nhist1];
   char *label2[Nhist2];
   char *labelp[Nprof];


   // Saving labels for gif plots 
   //   label1[0] = &"HcalRecHitTask_energy_in_cone_HF_gamma.gif";

   label1[0] = &"RecHits_energy_HB.gif";
   label1[1] = &"RecHits_energy_HE.gif";
   label1[2] = &"RecHits_energy_HO.gif";
   label1[3] = &"RecHits_energy_HF.gif";

   label1[4] = &"N_HB.gif";
   label1[5] = &"N_HE.gif";
   label1[6] = &"N_HO.gif";
   label1[7] = &"N_HF.gif";

   label1[8]   = &"occupancy_vs_ieta_HB1.gif";
   label1[9]   = &"occupancy_vs_ieta_HB2.gif";
   label1[10]  = &"occupancy_vs_ieta_HE1.gif";
   label1[11]  = &"occupancy_vs_ieta_HE2.gif";
   label1[12]  = &"occupancy_vs_ieta_HE3.gif";
   label1[13]  = &"occupancy_vs_ieta_HO.gif";
   label1[14]  = &"occupancy_vs_ieta_HF1.gif";
   label1[15]  = &"occupancy_vs_ieta_HF2.gif";

   labelp[0] = &"emean_vs_ieta_HB1.gif";
   labelp[1] = &"emean_vs_ieta_HB2.gif";
   labelp[2] = &"emean_vs_ieta_HE1.gif";
   labelp[3] = &"emean_vs_ieta_HE2.gif";
   labelp[4] = &"emean_vs_ieta_HE3.gif";
   labelp[5] = &"emean_vs_ieta_HO.gif";
   labelp[6] = &"emean_vs_ieta_HF1.gif";
   labelp[7] = &"emean_vs_ieta_HF2.gif";

   labelp[8]  = &"emean_seq_HB1.gif";
   labelp[9]  = &"emean_seq_HB2.gif";
   labelp[10] = &"emean_seq_HE1.gif";
   labelp[11] = &"emean_seq_HE2.gif";
   labelp[12] = &"emean_seq_HE3.gif";
   labelp[13] = &"emean_seq_HO.gif";
   labelp[14] = &"emean_seq_HF1.gif";
   labelp[15] = &"emean_seq_HF2.gif";

 
   f1->cd("DQMData/HcalRecHitsV/HcalRecHitTask");
   gDirectory->pwd();

   f1_hist1[0] = HcalRecHitTask_energy_of_rechits_HB;
   f1_hist1[1] = HcalRecHitTask_energy_of_rechits_HE;
   f1_hist1[2] = HcalRecHitTask_energy_of_rechits_HO;
   f1_hist1[3] = HcalRecHitTask_energy_of_rechits_HF;

   f1_hist1[4] = N_HB;
   f1_hist1[5] = N_HE;
   f1_hist1[6] = N_HO;
   f1_hist1[7] = N_HF;

   f1_hist1[8]  = occupancy_vs_ieta_HB1;
   f1_hist1[9]  = occupancy_vs_ieta_HB2;
   f1_hist1[10] = occupancy_vs_ieta_HE1;
   f1_hist1[11] = occupancy_vs_ieta_HE2;
   f1_hist1[12] = occupancy_vs_ieta_HE3;
   f1_hist1[13] = occupancy_vs_ieta_HO;
   f1_hist1[14] = occupancy_vs_ieta_HF1;
   f1_hist1[15] = occupancy_vs_ieta_HF2;

   f1_prof[0] = emean_vs_ieta_HB1;
   f1_prof[1] = emean_vs_ieta_HB2;
   f1_prof[2] = emean_vs_ieta_HE1;
   f1_prof[3] = emean_vs_ieta_HE2;
   f1_prof[4] = emean_vs_ieta_HE3;
   f1_prof[5] = emean_vs_ieta_HO;
   f1_prof[6] = emean_vs_ieta_HF1;
   f1_prof[7] = emean_vs_ieta_HF2;

   f1_prof[8]  = emean_seq_HB1;
   f1_prof[9]  = emean_seq_HB2;
   f1_prof[10] = emean_seq_HE1;
   f1_prof[11] = emean_seq_HE2;
   f1_prof[12] = emean_seq_HE3;
   f1_prof[13] = emean_seq_HO;
   f1_prof[14] = emean_seq_HF1;
   f1_prof[15] = emean_seq_HF2;


   f2->cd("DQMData/HcalRecHitsV/HcalRecHitTask");
   gDirectory->pwd();

   f2_hist1[0] = HcalRecHitTask_energy_of_rechits_HB;
   f2_hist1[1] = HcalRecHitTask_energy_of_rechits_HE;
   f2_hist1[2] = HcalRecHitTask_energy_of_rechits_HO;
   f2_hist1[3] = HcalRecHitTask_energy_of_rechits_HF;

   f2_hist1[4] = N_HB;
   f2_hist1[5] = N_HE;
   f2_hist1[6] = N_HO;
   f2_hist1[7] = N_HF;

   f2_hist1[8] = occupancy_vs_ieta_HB1;
   f2_hist1[9] = occupancy_vs_ieta_HB2;
   f2_hist1[10] = occupancy_vs_ieta_HE1;
   f2_hist1[11] = occupancy_vs_ieta_HE2;
   f2_hist1[12] = occupancy_vs_ieta_HE3;
   f2_hist1[13] = occupancy_vs_ieta_HO;
   f2_hist1[14] = occupancy_vs_ieta_HF1;
   f2_hist1[15] = occupancy_vs_ieta_HF2;

   f2_prof[0] = emean_vs_ieta_HB1;
   f2_prof[1] = emean_vs_ieta_HB2;
   f2_prof[2] = emean_vs_ieta_HE1;
   f2_prof[3] = emean_vs_ieta_HE2;
   f2_prof[4] = emean_vs_ieta_HE3;
   f2_prof[5] = emean_vs_ieta_HO;
   f2_prof[6] = emean_vs_ieta_HF1;
   f2_prof[7] = emean_vs_ieta_HF2;

   f2_prof[8]  = emean_seq_HB1;
   f2_prof[9]  = emean_seq_HB2;
   f2_prof[10] = emean_seq_HE1;
   f2_prof[11] = emean_seq_HE2;
   f2_prof[12] = emean_seq_HE3;
   f2_prof[13] = emean_seq_HO;
   f2_prof[14] = emean_seq_HF1;
   f2_prof[15] = emean_seq_HF2;


   //
   f1_hist1[0]->GetXaxis()->SetTitle("HB RecHits energy (GeV)");
   f1_hist1[1]->GetXaxis()->SetTitle("HE RecHits energy (GeV)");
   f1_hist1[2]->GetXaxis()->SetTitle("HO RecHits energy (GeV)");
   f1_hist1[3]->GetXaxis()->SetTitle("HF RecHits energy (GeV)");

   // NB !!!!!
   f2_hist1[4]->GetXaxis()->SetTitle("Number of HB RecHits");
   f2_hist1[5]->GetXaxis()->SetTitle("Number of HE RecHits");
   f2_hist1[6]->GetXaxis()->SetTitle("Number of HO RecHits");
   f2_hist1[7]->GetXaxis()->SetTitle("Number of HF RecHits");

   f1_hist1[8]->GetXaxis()->SetTitle("HB depth 1: occupancy vs ieta");
   f1_hist1[9]->GetXaxis()->SetTitle("HB depth 2: occupancy vs ieta");
   f1_hist1[10]->GetXaxis()->SetTitle("HE depth 1: occupancy vs ieta");
   f1_hist1[11]->GetXaxis()->SetTitle("HE depth 2: occupancy vs ieta");
   f1_hist1[12]->GetXaxis()->SetTitle("HE depth 3: occupancy vs ieta");
   f1_hist1[13]->GetXaxis()->SetTitle("HO: occupancy vs ieta");
   f1_hist1[14]->GetXaxis()->SetTitle("HF depth 1: occupancy vs ieta");
   f1_hist1[15]->GetXaxis()->SetTitle("HF depth 2: occupancy vs ieta");

   f1_prof[0]->GetXaxis()->SetTitle("Mean energy vs ieta (GeV) HB depth1");
   f1_prof[1]->GetXaxis()->SetTitle("Mean energy vs ieta (GeV) HB depth2");
   f1_prof[2]->GetXaxis()->SetTitle("Mean energy vs ieta (GeV) HE depth1");
   f1_prof[3]->GetXaxis()->SetTitle("Mean energy vs ieta (GeV) HE depth2");
   f1_prof[4]->GetXaxis()->SetTitle("Mean energy vs ieta (GeV) HE depth3");
   f1_prof[5]->GetXaxis()->SetTitle("Mean energy vs ieta (GeV) HO ");
   f1_prof[6]->GetXaxis()->SetTitle("Mean energy vs ieta (GeV) HF depth1");
   f1_prof[7]->GetXaxis()->SetTitle("Mean energy vs ieta (GeV) HF depth2");

   f1_prof[8]-> GetXaxis()->SetTitle("HB depth 1: mean energy (GeV) sequential channels");
   f1_prof[9]-> GetXaxis()->SetTitle("HB depth 2: mean energy (GeV) sequential channels");
   f1_prof[10]->GetXaxis()->SetTitle("HE depth 1: mean energy (GeV) sequential channels");
   f1_prof[11]->GetXaxis()->SetTitle("HE depth 2: mean energy (GeV) sequential channels");
   f1_prof[12]->GetXaxis()->SetTitle("HE depth 3: mean energy (GeV) sequential channels");
   f1_prof[13]->GetXaxis()->SetTitle("HO: mean energy (GeV) vs ieta");
   f1_prof[14]->GetXaxis()->SetTitle("HF depth 1: mean energy (GeV) sequential channels");
   f1_prof[15]->GetXaxis()->SetTitle("HF depth 2: mean energy (GeV) sequential channels");

   //
   //   f1_hist1[8]->SetMaximum(0.5);

   //
   //   f1_prof[0]->SetMaximum(40.);
   // f1_hist[7]->GetXaxis()->SetRangeUser(0.,160.);
   // hist1->GetXaxis()->SetNdivisions(-21);
   // hist1->GetYaxis()->SetNdivisions(-1003);


   //  1D-histo
  for (int i = 0; i < Nhist1; i++){

    TCanvas *myc = new TCanvas("myc","",800,600);
    myc->SetGrid();

    if(i < 4) { gPad->SetLogy(1);}
    else {gPad->SetLogy(0);}

    f1_hist1[i]->SetTitle("");
    f2_hist1[i]->SetTitle("");

    f1_hist1[i]->SetLineColor(41);
    if(i >= 8)  f1_hist1[i]->SetLineWidth(2);  
    f1_hist1[i]->SetMarkerColor(41);
    f1_hist1[i]->SetMarkerStyle(20);
    f1_hist1[i]->SetMarkerSize(0.02);  

    f2_hist1[i]->SetLineColor(43);
    if(i >= 8) f2_hist1[i]->SetLineWidth(2);  
    f2_hist1[i]->SetLineStyle(2); 
    f2_hist1[i]->SetMarkerColor(43);
    f2_hist1[i]->SetMarkerStyle(20);
    f2_hist1[i]->SetMarkerSize(0.02);  

    if( i <=7 ) {      
       TPaveStats *ptstats = new TPaveStats(0.8,0.8,0.99,1.0,"brNDC");
       ptstats->SetTextColor(41);
       f1_hist1[i]->GetListOfFunctions()->Add(ptstats);
       ptstats->SetParent(f1_hist1[i]->GetListOfFunctions());
       TPaveStats *ptstats = new TPaveStats(0.8,0.6,0.99,0.8,"brNDC");
       ptstats->SetTextColor(43);
       f2_hist1[i]->GetListOfFunctions()->Add(ptstats);
       ptstats->SetParent(f2_hist1[i]->GetListOfFunctions());

       f2_hist1[i]->Draw("hist"); // "stat"
       f1_hist1[i]->Draw("hist sames");
    }
    else {
      f1_hist1[i]->SetStats(kFALSE);   
      f2_hist1[i]->SetStats(kFALSE); 

      f1_hist1[i]->Draw("hist");   
      f2_hist1[i]->Draw("hist same");   
    }

    TLegend *leg = new TLegend(0.03, 0.90, 0.28, 0.98, "","brNDC");    
    leg->SetBorderSize(2);
    leg->SetFillStyle(1001); 
    leg->AddEntry(f1_hist1[i],"210pre9 startup cond.","l");
    leg->AddEntry(f2_hist1[i],"210pre9 ideal cond.","l");

    leg->Draw();   
    
    myc->SaveAs(label1[i]);
    
  }


   //  Profiles
  for (int i = 0; i < Nprof; i++){

    if(i <= 7 ) { TCanvas *myc = new TCanvas("myc","",800,600);}
    else {
      gStyle->SetPadLeftMargin(0.06);
      gStyle->SetPadRightMargin(0.03);
      TCanvas *myc = new TCanvas("myc","",1200,600);
    }

    myc->SetGrid();
  
    f1_prof[i]->SetErrorOption("");
    f2_prof[i]->SetErrorOption("");

    f1_prof[i]->SetStats(kFALSE);   
    f2_prof[i]->SetStats(kFALSE); 
    
    f1_prof[i]->SetTitle("");
    f2_prof[i]->SetTitle("");


    if( i >= 8) {

      fp1[i] = f1_prof[i]->ProjectionX();    
      fp2[i] = f2_prof[i]->ProjectionX();    

      fp1[i]->SetStats(kFALSE);   
      fp2[i]->SetStats(kFALSE); 

      char* title;
      title = f1_prof[i]->GetXaxis()->GetTitle();
      fp1[i]->GetXaxis()->SetTitle(title);


      int nbins = fp1[i]->GetNbinsX();
      for (int j = 1; j < nbins; j++) {
	fp1[i]->SetBinError(j, 0.);
	fp2[i]->SetBinError(j, 0.);
      }

      fp1[i]->SetLineWidth(0); 
      fp1[i]->SetLineColor(0); // 5 yellow
      fp1[i]->SetLineStyle(1); 
      fp1[i]->SetMarkerColor(2);
      fp1[i]->SetMarkerStyle(20);
      fp1[i]->SetMarkerSize(0.5);
    
      fp2[i]->SetLineWidth(0); 
      fp2[i]->SetLineColor(0); // 45 blue
      fp2[i]->SetLineStyle(2); 
      fp2[i]->SetMarkerColor(4); 
      fp2[i]->SetMarkerStyle(22);
      fp2[i]->SetMarkerSize(0.5);

      fp1[i]->Draw("p9");   
      fp2[i]->Draw("p9same");   

      TLegend *leg = new TLegend(0.83, 0.87, 0.98, 0.97, "","brNDC");    
      leg->SetBorderSize(2);
      leg->SetFillStyle(1001); 
      leg->AddEntry(fp1[i],"210pre9 startup cond.","pl");
      leg->AddEntry(fp2[i],"210pre9 ideal cond.","pl");  
    }
    if( i< 8) {
      f1_prof[i]->SetLineColor(41);
      f1_prof[i]->SetLineStyle(1);     
      f1_prof[i]->SetLineWidth(1); 
      f1_prof[i]->SetMarkerColor(41);
      f1_prof[i]->SetMarkerStyle(21);
      f1_prof[i]->SetMarkerSize(0.8);  
      
      f2_prof[i]->SetLineColor(43);
      f2_prof[i]->SetLineStyle(1);  
      f2_prof[i]->SetLineWidth(1); 
      f2_prof[i]->SetMarkerColor(43);
      f2_prof[i]->SetMarkerStyle(22);
      f2_prof[i]->SetMarkerSize(1.0);  

      f1_prof[i]->Draw("hist pl");   
      f2_prof[i]->Draw("hist pl same");   

      TLegend *leg = new TLegend(0.83, 0.87, 0.98, 0.97, "","brNDC");    
      leg->SetBorderSize(2);
      leg->SetFillStyle(1001); 
      leg->AddEntry(f1_prof[i],"210pre9 startup cond.","pl");
      leg->AddEntry(f2_prof[i],"210pre9 ideal cond.","pl");
    }


     leg->Draw("");   
     
     myc->SaveAs(labelp[i]);

  }


   // close ROOT files
   //
   f1.Close() ;  
   f2.Close() ;
   
   return ;  
     
}
