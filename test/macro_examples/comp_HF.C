// Commands executed in a GLOBAL scope, e.g. created hitograms aren't erased...
{

   TCanvas *myc = new TCanvas("myc","",800,600);
      
   TFile f1("~/Validation/170_on_simhits_170/CaloTowersValidationHF.root");
   TFile f2("~/Validation/180_pre5_on_simhits_170/CaloTowersValidationHF.root");

   
   // service variables
   //
   const int Nhist1 = 2;
   const int Nhist2 = 1;
   const int Nprof  = 1;

   TH1F* f1_hist1[Nhist1];
   TH1F* f2_hist1[Nhist1];

   TH2F*     f1_hist2[Nhist2];
   TProfile* f1_histp[Nprof];

   TH2F*     f2_hist2[Nhist2];
   TProfile* f2_histp[Nprof];

   char *label1[Nhist1];
   char *label2[Nhist2];

   label1[0] = &"HcalRecHitTask_energy_in_cone_HF.gif";
   label1[1] = &"HcalRecHitTask_number_of_rechits_in_cone_HF.gif";

   label2[0] = &"HcalRecHitTask_energy_rechits_vs_simhits_HF.gif";


   f1->cd("DQMData/HcalRecHitsV/HcalRecHitTask");
   gDirectory->pwd();
   f1_hist1[0] = HcalRecHitTask_sum_of_rechits_energy_in_cone_HF;
   f1_hist1[1] = HcalRecHitTask_number_of_rechits_in_cone_HF;

   f1_hist2[0] = HcalRecHitTask_energy_rechits_vs_simhits_HF;
   f1_histp[0] = HcalRecHitTask_energy_rechits_vs_simhits_profile_HF; 

   f2->cd("DQMData/HcalRecHitsV/HcalRecHitTask");
   gDirectory->pwd();
   f2_hist1[0] = HcalRecHitTask_sum_of_rechits_energy_in_cone_HF;
   f2_hist1[1] = HcalRecHitTask_number_of_rechits_in_cone_HF;

   f2_hist2[0] = HcalRecHitTask_energy_rechits_vs_simhits_HF;
   f2_histp[0] = HcalRecHitTask_energy_rechits_vs_simhits_profile_HF; 



   f1_hist1[0]->GetXaxis()->SetTitle("HF hcal energy in cone (GeV)");
   f1_hist1[1]->GetXaxis()->SetTitle("HF N_{rechits} in cone");

   f1_hist2[0]->GetXaxis()->SetTitle("HF RecHits energy vs SimHits energy (GeV)");


   // f1_hist[0]->SetMaximum(600.);

   // f1_hist[2]->GetXaxis()->SetRangeUser(0.,1200.);
   // f1_hist[7]->GetXaxis()->SetRangeUser(0.,160.);
   // hist1->GetXaxis()->SetNdivisions(-21);
   // hist1->GetYaxis()->SetNdivisions(-1003);


   //  1D-histo

   for (int i = 0; i < Nhist1; i++){

    f1_hist1[i]->SetStats(kFALSE);   
    f2_hist1[i]->SetStats(kFALSE); 
    
    f1_hist1[i]->SetTitle("");
    f2_hist1[i]->SetTitle("");

    // diffferent histo colors and styles
    f1_hist1[i]->SetLineColor(41);
    f1_hist1[i]->SetLineWidth(2); 
    f1_hist1[i]->SetLineStyle(1); 
    
    f2_hist1[i]->SetLineColor(42);
    f2_hist1[i]->SetLineWidth(3);     
    f2_hist1[i]->SetLineStyle(2);  


    TLegend *leg = new TLegend(0.68, 0.82, 0.98, 0.97, "","brNDC");
    leg->SetBorderSize(2);
    //  leg->SetFillColor(51); // see new color definition above
    leg->SetFillStyle(1001); 
    leg->AddEntry(f1_hist1[i],"CMSSW_170","l");
    leg->AddEntry(f2_hist1[i],"CMSSW_180","l");

    f1_hist1[i]->Draw("hist");   
    f2_hist1[i]->Draw("hist same");   
    
    leg->Draw();   
    
    myc->SaveAs(label1[i]);

   }     

   //  2D-histo
   for (int i = 0; i < Nhist2; i++){

     f1_hist2[i]->SetStats(kFALSE);   
     f2_hist2[i]->SetStats(kFALSE); 
     
     f1_hist2[i]->SetTitle("");
     f2_hist2[i]->SetTitle("");

     f1_hist2[i]->SetLineColor(2);
     f1_hist2[i]->SetLineWidth(2); 
     f1_hist2[i]->SetMarkerColor(41);
     f1_hist2[i]->SetMarkerStyle(20);
     f1_hist2[i]->SetMarkerSize(0.2);  
     if(i == 0) f1_hist2[i]->SetMarkerSize(0.02);  
     
     
     f2_hist2[i]->SetLineColor(3);
     f2_hist2[i]->SetLineWidth(3); 
     f2_hist2[i]->SetMarkerColor(42);
     f2_hist2[i]->SetMarkerStyle(20);
     f2_hist2[i]->SetMarkerSize(0.2);  
     if(i == 0) f2_hist2[i]->SetMarkerSize(0.02);  
     
     f1_hist2[i]->Draw("P");   
     f2_hist2[i]->Draw("PSAME");   
     
     if(i == 0) { // rechits vs simhits 
       f1_histp[i]->SetLineColor(2);
       f1_histp[i]->SetLineStyle(1);     
       f1_histp[i]->SetLineWidth(2); 
       
       f1_histp[i]->Draw("e same");
       
       f2_histp[i]->SetLineColor(3);
       f2_histp[i]->SetLineStyle(2);     
       f2_histp[i]->SetLineWidth(2);
       
       f2_histp[i]->Draw("e same");
     }
     
     TLegend *leg = new TLegend(0.38, 0.82, 0.68, 0.97, "","brNDC");    
     leg->SetBorderSize(2);
     leg->SetFillStyle(1001); 
     leg->AddEntry(f1_hist2[i],"CMSSW_170","l");
     leg->AddEntry(f2_hist2[i],"CMSSW_180","l");
     
     leg->Draw();   
     
     myc->SaveAs(label2[i]);

   }
   
   // close ROOT files
   //
   f1.Close() ;  
   f2.Close() ;
   
   return ;  
     
}
