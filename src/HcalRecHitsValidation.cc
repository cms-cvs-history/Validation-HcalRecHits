#include "Validation/HcalRecHits/interface/HcalRecHitsValidation.h"


HcalRecHitsValidation::HcalRecHitsValidation(edm::ParameterSet const& conf) {
  // DQM ROOT output
  outputFile_ = conf.getUntrackedParameter<std::string>("outputFile", "myfile.root");

  if ( outputFile_.size() != 0 ) {
    edm::LogInfo("OutputInfo") << " Hcal RecHit Task histograms will be saved to '" << outputFile_.c_str() << "'";
  } else {
    edm::LogInfo("OutputInfo") << " Hcal RecHit Task histograms will NOT be saved";
  }

  dbe_ = 0;
  // get hold of back-end interface
  dbe_ = edm::Service<DaqMonitorBEInterface>().operator->();
   
  Char_t histo[20];

  hcalselector_ = conf.getUntrackedParameter<std::string>("hcalselector", "all");
  ecalselector_ = conf.getUntrackedParameter<std::string>("ecalselector", "yes");
  eventype_     = conf.getUntrackedParameter<std::string>("eventype", "single");
  sign_         = conf.getUntrackedParameter<std::string>("sign", "*");

  mc_           = conf.getUntrackedParameter<std::string>("mc", "yes");

  subdet_ = 0;
  if (hcalselector_ == "HB"  ) subdet_ = 1;
  if (hcalselector_ == "HE"  ) subdet_ = 2;
  if (hcalselector_ == "HO"  ) subdet_ = 3;
  if (hcalselector_ == "HF"  ) subdet_ = 4;
  if (hcalselector_ == "all" ) subdet_ = 5;

  etype_ = 1;
  if (eventype_ == "multi") etype_ = 2;

  iz = 1;
  if(sign_ == "-") iz = -1;
  if(sign_ == "*") iz = 0;

  imc = 1;
  if(mc_ == "no") imc = 0;

  if ( dbe_ ) {
    std::cout << " dbe_->setCurrentFolder" << std::endl; 
    dbe_->setCurrentFolder("HcalRecHitTask");


    //  ALL

    if (ecalselector_ == "yes") {
      sprintf  (histo, "map_ecal" );
      map_ecal = dbe_->book2D(histo, histo, 70, -3.045, 3.045, 72, -3.1415926536, 3.1415926536);
    }

    sprintf  (histo, "map_depth1" );
    map_depth1 = dbe_->book2D(histo, histo, 82, -41., 41., 72, 0., 72.);
    sprintf  (histo, "map_depth2" );
    map_depth2 = dbe_->book2D(histo, histo, 82, -41., 41., 72, 0., 72.);
    sprintf  (histo, "map_depth3" );
    map_depth3 = dbe_->book2D(histo, histo, 82, -41., 41., 72, 0., 72.);
    sprintf  (histo, "map_depth4" );
    map_depth4 = dbe_->book2D(histo, histo, 82, -41., 41., 72, 0., 72.);

    sprintf  (histo, "map_depth1_cuts" );
    map_depth1_cuts = dbe_->book2D(histo, histo, 82, -41., 41., 72, 0., 72.);
    sprintf  (histo, "map_depth2_cuts" );
    map_depth2_cuts = dbe_->book2D(histo, histo, 82, -41., 41., 72, 0., 72.);
    sprintf  (histo, "map_depth3_cuts" );
    map_depth3_cuts = dbe_->book2D(histo, histo, 82, -41., 41., 72, 0., 72.);
    sprintf  (histo, "map_depth4_cuts" );
    map_depth4_cuts = dbe_->book2D(histo, histo, 82, -41., 41., 72, 0., 72.);


    sprintf  (histo, "profile_z1" );
    profile_z1 = dbe_->bookProfile(histo, histo, 82, -41., 41., 2000, -2000., 2000.);
    sprintf  (histo, "profile_z2" );
    profile_z2 = dbe_->bookProfile(histo, histo, 82, -41., 41., 2000, -2000., 2000.);
    sprintf  (histo, "profile_z3" );
    profile_z3 = dbe_->bookProfile(histo, histo, 82, -41., 41., 2000, -2000., 2000.);
    sprintf  (histo, "profile_z4" );
    profile_z4 = dbe_->bookProfile(histo, histo, 82, -41., 41., 2000, -2000., 2000.);


    sprintf  (histo, "map_econe_around_MC_depth1" );
    map_econe_depth1 =
      dbe_->book2D(histo, histo, 520, -5.2, 5.2, 72, -3.1415926536, 3.1415926536);

    sprintf  (histo, "map_econe_around_MC_depth2" );
    map_econe_depth2 =
      dbe_->book2D(histo, histo, 520, -5.2, 5.2, 72, -3.1415926536, 3.1415926536);

    sprintf  (histo, "map_econe_around_MC_depth3" );
    map_econe_depth3 =
      dbe_->book2D(histo, histo, 520, -5.2, 5.2, 72, -3.1415926536, 3.1415926536);

    sprintf  (histo, "map_econe_around_MC_depth4" );
    map_econe_depth4 =
      dbe_->book2D(histo, histo, 520, -5.2, 5.2, 72, -3.1415926536, 3.1415926536);


    if(subdet_ != 0) { // just not for noise  

      //    meEnConeEtaProfiel_depth1->Fill(eta_RecHit, HcalCone_d1);
      
      sprintf (histo, "HcalRecHitTask_En_rechits_cone_profile_vs_ieta_depth1");
      meEnConeEtaProfile_depth1 = dbe_->bookProfile(histo, histo, 82, -41., 41., 200, 0., 200.);   
      
      sprintf (histo, "HcalRecHitTask_En_rechits_cone_profile_vs_ieta_depth2");
      meEnConeEtaProfile_depth2 = dbe_->bookProfile(histo, histo, 82, -41., 41., 200, 0., 200.);  
      
      sprintf (histo, "HcalRecHitTask_En_rechits_cone_profile_vs_ieta_depth3");
      meEnConeEtaProfile_depth3 = dbe_->bookProfile(histo, histo, 82, -41., 41., 200, 0., 200.);  
      
      sprintf (histo, "HcalRecHitTask_En_rechits_cone_profile_vs_ieta_depth4");
      meEnConeEtaProfile_depth4 = dbe_->bookProfile(histo, histo, 82, -41., 41., 200, 0., 200.);  
      
    }

    if(etype_ == 1 && subdet_ != 0) { // single part., not for noise

      sprintf  (histo, "Delta_phi_cluster-MC");
      meDeltaPhi =  dbe_->book2D(histo, histo, 520, -5.2, 5.2, 60, -0.6, 0.6);

      sprintf  (histo, "Delta_eta_cluster-MC");
      meDeltaEta =  dbe_->book2D(histo, histo, 520, -5.2, 5.2, 60, -0.6, 0.6);
      
      sprintf  (histo, "Delta_phi_simcluster-MC");
      meDeltaPhiS =  dbe_->book2D(histo, histo, 520, -5.2, 5.2, 60, -0.6, 0.6);

      sprintf  (histo, "Delta_eta_simcluster-MC");
      meDeltaEtaS =  dbe_->book2D(histo, histo, 520, -5.2, 5.2, 60, -0.6, 0.6);
      

    }
    // NOISE-specific

    if (hcalselector_ == "noise" ){

      sprintf  (histo, "e_hb" ) ;
      e_hb = dbe_->book1D(histo, histo,1000, -5., 5.);
      sprintf  (histo, "e_he" ) ;
      e_he = dbe_->book1D(histo, histo,1000, -5., 5.);
      sprintf  (histo, "e_ho" ) ;
      e_ho = dbe_->book1D(histo, histo,1000, -5., 5.);
      sprintf  (histo, "e_hfl" ) ;
      e_hfl = dbe_->book1D(histo, histo,2000, -10., 10.);
      sprintf  (histo, "e_hfs" ) ;
      e_hfs = dbe_->book1D(histo, histo,2000, -10., 10.);

    }
    // ************** HB **********************************
    if (subdet_ == 1 || subdet_ == 5 ){
     
      if(etype_ == 1 && subdet_ == 1 ) { 
	sprintf (histo, "HcalRecHitTask_number_of_rechits_in_cone_HB" ) ;
	meNumRecHitsConeHB    = dbe_->book1D(histo, histo, 100, 0., 100.);
	
	sprintf (histo, "HcalRecHitTask_number_of_rechits_above_1GeV_HB");
	meNumRecHitsThreshHB = dbe_->book1D(histo, histo,  30, 0., 30.); 
	
	sprintf (histo, "HcalRecHitTask_sum_of_rechits_energy_HB" ) ;
	meSumRecHitsEnergyHB = dbe_->book1D(histo,histo, 60 , -20., 280.);
	
	sprintf (histo, "HcalRecHitTask_sum_of_rechits_energy_in_cone_HB" ) ;
	meSumRecHitsEnergyConeHB = dbe_->book1D(histo,histo, 60 , -20., 280.); 

	if (ecalselector_ == "yes") {  
	  sprintf (histo, "HcalRecHitTask_energy_hcal_vs_ecal_HB");
	  meEnergyHcalVsEcalHB = dbe_->book2D(histo, histo, 300, 0., 150., 300, 0., 150.);  	
	  sprintf (histo, "HcalRecHitTask_number_of_ecalrechits_in_cone_HB");
	  meNumEcalRecHitsConeHB = dbe_->book1D(histo, histo,   300, 0., 300.);
	  
	  sprintf (histo, "HcalRecHitTask_energy_ecal_plus_hcal_HB" ) ;
	  meEcalHcalEnergyHB = dbe_->book1D(histo,histo, 60 , -20., 280.);
	  
	  sprintf (histo, "HcalRecHitTask_energy_ecal_plus_hcal_in_cone_HB" ) ;
	  meEcalHcalEnergyConeHB =  dbe_->book1D(histo,histo, 60 , -20., 280.);
	}
      }
      
      sprintf (histo, "HcalRecHitTask_energy_of_rechits_HB" ) ;
      meRecHitsEnergyHB = dbe_->book1D(histo, histo, 210 , -10. , 200.); 

      sprintf (histo, "HcalRecHitTask_timing_HB" ) ;
      meTimeHB = dbe_->book1D(histo, histo, 2000 , -100. , 100.); 
      
      sprintf (histo, "HcalRecHitTask_timing_vs_energy_HB" ) ;
      meTE_HB = dbe_->book2D(histo, histo, 200, -5., 95.,  220, -10., 100.);
      
      sprintf (histo, "HcalRecHitTask_timing_vs_energy_HB_depth1" ) ;
      meTE_HB1 = dbe_->book2D(histo, histo, 200, -5., 95.,  220, -10., 100.);
      
      sprintf (histo, "HcalRecHitTask_timing_vs_energy_HB_depth2" ) ;
      meTE_HB2 = dbe_->book2D(histo, histo, 200, -5., 95.,  220, -10., 100.);
      
      sprintf (histo, "HcalRecHitTask_timing_vs_energy_profile_HB" ) ;
      meTEprofileHB = dbe_->bookProfile(histo, histo, 100, -5., 95.,  100, -10., 100.); 

      sprintf (histo, "HcalRecHitTask_energy_rechits_vs_simhits_HB");
      meRecHitSimHitHB = dbe_->book2D(histo, histo, 120, 0., 1.2,  300, 0., 150.);

      sprintf (histo, "HcalRecHitTask_energy_rechits_vs_simhits_profile_HB");
      meRecHitSimHitProfileHB = dbe_->bookProfile(histo, histo, 120, 0., 1.2, 500, 0., 500.);  

    }

    // ********************** HE ************************************
    if ( subdet_ == 2 || subdet_ == 5 ){

      if(etype_ == 1 && subdet_ == 2 ) { 

	sprintf (histo, "HcalRecHitTask_number_of_rechits_in_cone_HE" ) ;
	meNumRecHitsConeHE    = dbe_->book1D(histo, histo, 100, 0., 100.);
	
	sprintf (histo, "HcalRecHitTask_number_of_rechits_above_1GeV_HE");
	meNumRecHitsThreshHE = dbe_->book1D(histo, histo,  30, 0., 30.);  
	
	sprintf (histo, "HcalRecHitTask_sum_of_rechits_energy_HE" ) ;
	meSumRecHitsEnergyHE = dbe_->book1D(histo,histo, 60 , -20., 280.);
	
	sprintf (histo, "HcalRecHitTask_sum_of_rechits_energy_in_cone_HE" ) ;
	meSumRecHitsEnergyConeHE = dbe_->book1D(histo,histo, 60 , -20., 280.);
	
	if (ecalselector_ == "yes") {  	
	  sprintf (histo, "HcalRecHitTask_energy_ecal_plus_hcal_HE" ) ;
	  meEcalHcalEnergyHE = dbe_->book1D(histo,histo, 80, -20., 380.);
	  
	  sprintf (histo, "HcalRecHitTask_energy_hcal_vs_ecal_HE");
	  meEnergyHcalVsEcalHE = dbe_->book2D(histo, histo, 300, 0., 150., 300, 0., 150.);
	  sprintf (histo, "HcalRecHitTask_number_of_ecalrechits_in_cone_HE");
	  meNumEcalRecHitsConeHE = dbe_->book1D(histo, histo, 300, 0., 300.);   
	  sprintf (histo, "HcalRecHitTask_energy_ecal_plus_hcal_in_cone_HE" ) ;
	  meEcalHcalEnergyConeHE =  dbe_->book1D(histo,histo, 60, -20., 280.);
	}	      
      }
      
      sprintf (histo, "HcalRecHitTask_energy_of_rechits_HE" ) ;
      meRecHitsEnergyHE = dbe_->book1D(histo, histo, 210, -10., 200.); 

      sprintf (histo, "HcalRecHitTask_timing_HE" ) ;
      meTimeHE = dbe_->book1D(histo, histo, 200 , -100. , 100.); 
            
      sprintf (histo, "HcalRecHitTask_timing_vs_energy_HE" ) ;
      meTE_HE = dbe_->book2D(histo, histo, 200, -5., 95.,  220, -10., 100.);
      
      sprintf (histo, "HcalRecHitTask_timing_vs_energy_HE_depth1" ) ;
      meTE_HE1 = dbe_->book2D(histo, histo, 200, -5., 95.,  220, -10., 100.);
      
      sprintf (histo, "HcalRecHitTask_timing_vs_energy_HE_depth2" ) ;
      meTE_HE2 = dbe_->book2D(histo, histo, 200, -5., 95.,  220, -10., 100.);
      
      sprintf (histo, "HcalRecHitTask_timing_vs_energy_profile_HE" ) ;
      meTEprofileHE = dbe_->bookProfile(histo, histo, 100, -5., 95.,  100, -10., 100.); 
            
      sprintf (histo, "HcalRecHitTask_energy_rechits_vs_simhits_HE");
      meRecHitSimHitHE = dbe_->book2D(histo, histo, 100, 0., 1.0,  300, 0., 150.);

      sprintf (histo, "HcalRecHitTask_energy_rechits_vs_simhits_profile_HE");
      meRecHitSimHitProfileHE = dbe_->bookProfile(histo, histo, 100, 0., 1.0, 500, 0., 500.);  
   
 
    }

    // ************** HO ****************************************
    if ( subdet_ == 3 || subdet_ == 5  ){

      if(etype_ == 1 && subdet_ == 3) { 
      
	sprintf (histo, "HcalRecHitTask_number_of_rechits_in_cone_HO" ) ;
	meNumRecHitsConeHO    = dbe_->book1D(histo, histo, 100, 0 , 100.);
	
	sprintf (histo, "HcalRecHitTask_number_of_rechits_above_1GeV_HO");
	meNumRecHitsThreshHO = dbe_->book1D(histo, histo,   30, 0., 30.);   
	
	sprintf (histo, "HcalRecHitTask_sum_of_rechits_energy_HO" ) ;
	meSumRecHitsEnergyHO = dbe_->book1D(histo,histo, 60 , -20., 280.);
	
	sprintf (histo, "HcalRecHitTask_sum_of_rechits_energy_in_cone_HO" ) ;
	meSumRecHitsEnergyConeHO = dbe_->book1D(histo,histo, 60 , -20., 280.);   
      }      

      sprintf (histo, "HcalRecHitTask_energy_of_rechits_HO" ) ;
      meRecHitsEnergyHO = dbe_->book1D(histo, histo, 210 , -10. , 200.); 

      sprintf (histo, "HcalRecHitTask_timing_HO" ) ;
      meTimeHO = dbe_->book1D(histo, histo, 2000 , -100., 100.); 

      sprintf (histo, "HcalRecHitTask_timing_vs_energy_HO" ) ;
      meTE_HO= dbe_->book2D(histo, histo, 200, -5., 95., 220, -10., 100.);
      
      sprintf (histo, "HcalRecHitTask_timing_vs_energy_profile_HO" ) ;
      meTEprofileHO = dbe_->bookProfile(histo, histo, 100, -5., 95.,  110, -10., 100.); 
      
      
      sprintf (histo, "HcalRecHitTask_energy_rechits_vs_simhits_HO");
      meRecHitSimHitHO = dbe_->book2D(histo, histo, 120, 0., 1.2,  300, 0., 300.);

      sprintf (histo, "HcalRecHitTask_energy_rechits_vs_simhits_profile_HO");
      meRecHitSimHitProfileHO = dbe_->bookProfile(histo, histo, 120, 0., 1.2, 500, 0., 500.);  
        
    }    
  
    // ********************** HF ************************************
    if ( subdet_ == 4 || subdet_ == 5 ){

      if(etype_ == 1 &&  subdet_ == 4) { 

	sprintf (histo, "HcalRecHitTask_number_of_rechits_in_cone_HF" ) ;
	meNumRecHitsConeHF    = dbe_->book1D(histo, histo, 100, 0 , 100.);
	
	sprintf (histo, "HcalRecHitTask_sum_of_rechits_energy_HF" ) ;
	meSumRecHitsEnergyHF = dbe_->book1D(histo,histo, 60 , -20., 280.);
	
	sprintf (histo, "HcalRecHitTask_sum_of_rechits_energy_in_cone_HF" ) ;
	meSumRecHitsEnergyConeHF = dbe_->book1D(histo,histo, 60 , -20., 280.);   
	sprintf (histo, "HcalRecHitTask_sum_of_rechits_energy_in_cone_HFL" ) ;
	meSumRecHitsEnergyConeHFL = dbe_->book1D(histo,histo, 60 , -20., 280.);   
	sprintf (histo, "HcalRecHitTask_sum_of_rechits_energy_in_cone_HFS" ) ;
	meSumRecHitsEnergyConeHFS = dbe_->book1D(histo,histo, 60 , -20., 280.);   

      }

      sprintf (histo, "HcalRecHitTask_energy_of_rechits_HF" ) ;
      meRecHitsEnergyHF = dbe_->book1D(histo, histo, 210 , -10. , 200.); 

      sprintf (histo, "HcalRecHitTask_timing_HF" ) ;
      meTimeHF = dbe_->book1D(histo, histo, 2000 , -100. , 100.); 
      
      sprintf (histo, "HcalRecHitTask_timing_vs_energy_HF" ) ;
      meTE_HF = dbe_->book2D(histo, histo, 200, -5., 95., 220, -10., 100.);
      
      sprintf (histo, "HcalRecHitTask_timing_vs_energy_HFL" ) ;
      meTE_HFL = dbe_->book2D(histo, histo, 200, -5., 95., 220, -10., 100.);
      
      sprintf (histo, "HcalRecHitTask_timing_vs_energy_HFS" ) ;
      meTE_HFS = dbe_->book2D(histo, histo, 200, -5., 95., 220, -10., 100.);
      
      sprintf (histo, "HcalRecHitTask_timing_vs_energy_profile_HF" ) ;
      meTEprofileHF = dbe_->bookProfile(histo, histo, 100, -5., 95.,  100, -10., 1700.); 
            
      sprintf (histo, "HcalRecHitTask_energy_rechits_vs_simhits_HF");
      meRecHitSimHitHF  = dbe_->book2D(histo, histo, 120, 0., 60., 200, 0., 200.);      
      sprintf (histo, "HcalRecHitTask_energy_rechits_vs_simhits_HFL");
      meRecHitSimHitHFL = dbe_->book2D(histo, histo, 120, 0., 60., 200, 0., 200.);      
      sprintf (histo, "HcalRecHitTask_energy_rechits_vs_simhits_HFS");
      meRecHitSimHitHFS = dbe_->book2D(histo, histo, 120, 0., 60., 200, 0., 200.);

      sprintf (histo, "HcalRecHitTask_energy_rechits_vs_simhits_profile_HF");
      meRecHitSimHitProfileHF  = dbe_->bookProfile(histo, histo, 60, 0., 60., 250, 0., 500.);  
      sprintf (histo, "HcalRecHitTask_energy_rechits_vs_simhits_profile_HFL");
      meRecHitSimHitProfileHFL = dbe_->bookProfile(histo, histo, 60, 0., 60., 250, 0., 500.);  
      sprintf (histo, "HcalRecHitTask_energy_rechits_vs_simhits_profile_HFS");
      meRecHitSimHitProfileHFS = dbe_->bookProfile(histo, histo, 60, 0., 60., 250, 0., 500.);  
   
    }
  }
}

HcalRecHitsValidation::~HcalRecHitsValidation() {
   
  std::cout << " outputFile_.size() =  " << outputFile_.size() << std::endl;
  std::cout << " dbe_ = " << dbe_ << std::endl;
  if ( outputFile_.size() != 0 && dbe_ ) dbe_->save(outputFile_);
  
}

void HcalRecHitsValidation::endJob() {
  
  std::cout << " outputFile_.size() =  " << outputFile_.size() << std::endl;
  std::cout << " dbe_ = " << dbe_ << std::endl; 
  if ( outputFile_.size() != 0 && dbe_ ) dbe_->save(outputFile_);
}

void HcalRecHitsValidation::beginJob(const edm::EventSetup& c){ }

void HcalRecHitsValidation::analyze(edm::Event const& ev, edm::EventSetup const& c) {

  using namespace edm;

  // cuts for each subdet_ector mimiking  "Scheme B"
  double cutHB = 0.9, cutHE = 1.4, cutHO = 1.1, cutHFL = 1.2, cutHFS = 1.8; 

  // energy in HCAL
  double eHcal        = 0.;
  double eHcalCone    = 0.;  
  double eHcalConeHB  = 0.;  
  double eHcalConeHE  = 0.;  
  double eHcalConeHO  = 0.;  
  double eHcalConeHF  = 0.;  
  double eHcalConeHFL = 0.;  
  double eHcalConeHFS = 0.;  
  // Total numbet of RecHits in HCAL, in the cone, above 1 GeV theshold
  int nrechits       = 0;
  int nrechitsCone   = 0;
  int nrechitsThresh = 0;

  // energy in ECAL
  double eEcal       = 0.;
  double eEcalB      = 0.;
  double eEcalE      = 0.;
  double eEcalCone   = 0.;
  int numrechitsEcal = 0;

  // MC info 
  double phi_MC = -999999.;  // phi of initial particle from HepMC
  double eta_MC = -999999.;  // eta of initial particle from HepMC
  bool MC = false;

  // HCAL energy around MC eta-phi at all depths;
  double partR = 0.3;
  double ehcal_coneMC_1 = 0.;
  double ehcal_coneMC_2 = 0.;
  double ehcal_coneMC_3 = 0.;
  double ehcal_coneMC_4 = 0.;

  // Cone size for serach of the hottest HCAL cell around MC
  double searchR = 1.0; 
  double eps     = 0.001;

  // Single particle samples: actual eta-phi position of cluster around
  // hottest cell
  double etaHot  = 99999.; 
  double phiHot  = 99999.; 
  int    ietahot = 1000;
  int    iphihot = 1000;

  // MC information

  //  std::cout << "*** 1" << std::endl; 


  if(imc != 0) { 

  edm::Handle<edm::HepMCProduct> evtMC;
  //  ev.getByLabel("VtxSmeared",evtMC);
  ev.getByLabel("source",evtMC);
  if (!evtMC.isValid()) {
    std::cout << "no HepMCProduct found" << std::endl;    
  } else {
    MC=true;
    //    std::cout << "*** source HepMCProduct found"<< std::endl;
  }  

  // MC particle with highest pt is taken as a direction reference  
  double maxPt = -99999.;
  int npart    = 0;
  HepMC::GenEvent * myGenEvent = new  HepMC::GenEvent(*(evtMC->GetEvent()));
  for ( HepMC::GenEvent::particle_iterator p = myGenEvent->particles_begin();
	p != myGenEvent->particles_end(); ++p ) {
    double phip = (*p)->momentum().phi();
    double etap = (*p)->momentum().eta();
    //    phi_MC = phip;
    //    eta_MC = etap;
    double pt  = (*p)->momentum().perp();
    if(pt > maxPt) { npart++; maxPt = pt; phi_MC = phip; eta_MC = etap; }
  }
  //  std::cout << "*** Max pT = " << maxPt <<  std::endl;  

  }

  //   std::cout << "*** 2" << std::endl; 

  c.get<IdealGeometryRecord>().get (geometry);


  // Fill working vectors of HCAL RecHits quantities 
  fillRecHitsTmp(subdet_, ev); 

  //   std::cout << "*** 3" << std::endl; 


  //===========================================================================
  // IN ALL THE CASES : ieta-iphi maps 
  //===========================================================================

  // ECAL 
  if(ecalselector_ == "yes" && (subdet_ == 1 || subdet_ == 2 || subdet_ == 5)) {
    Handle<EBRecHitCollection> EcalRecHitEB;
    ev.getByLabel( "ecalRecHit" ,"EcalRecHitsEB" , EcalRecHitEB);
    const EBRecHitCollection *EBRecHit = EcalRecHitEB.product();
    
    for (EcalRecHitCollection::const_iterator RecHit = EBRecHit->begin(); RecHit != EBRecHit->end() ; ++RecHit) {
      EBDetId EBid = EBDetId(RecHit->id());
      
      const CaloCellGeometry* cellGeometry =
	geometry->getSubdetectorGeometry (EBid)->getGeometry (EBid) ;
      double eta = cellGeometry->getPosition ().eta () ;
      double phi = cellGeometry->getPosition ().phi () ;
      double en  = RecHit->energy();
      eEcal  += en;
      eEcalB += en;

      map_ecal->Fill(eta, phi, en);

      double r   = dR(eta_MC, phi_MC, eta, phi);
      if( r < partR)  {
	eEcalCone += en;
	numrechitsEcal++; 
      }
    }

    
    Handle<EERecHitCollection> EcalRecHitEE;
    ev.getByLabel( "ecalRecHit" ,"EcalRecHitsEE" , EcalRecHitEE);
    const EERecHitCollection *EERecHit = EcalRecHitEE.product();
    
    for (EcalRecHitCollection::const_iterator RecHit = EERecHit->begin(); RecHit != EERecHit->end() ; ++RecHit) {
      EEDetId EEid = EEDetId(RecHit->id());
      
      const CaloCellGeometry* cellGeometry =
	geometry->getSubdetectorGeometry (EEid)->getGeometry (EEid) ;
      double eta = cellGeometry->getPosition ().eta () ;
      double phi = cellGeometry->getPosition ().phi () ;	
      double en   = RecHit->energy();
      eEcal  += en;
      eEcalE += en;

      map_ecal->Fill(eta, phi, en);

      double r   = dR(eta_MC, phi_MC, eta, phi);
      if( r < partR)  {
	eEcalCone += en;
	numrechitsEcal++; 
      }
    }
  }     // end of ECAL selection 


  //   std::cout << "*** 4" << std::endl; 


  // Filling HCAL maps  -------------------------------------------------------
  double maxE = -99999.;
  for (unsigned int i = 0; i < cen.size(); i++) {

    int sub    = csub[i];
    int depth  = cdepth[i];
    int ieta   = cieta[i]; 
    int iphi   = ciphi[i]; 
    double en  = cen[i]; 
    double eta = ceta[i]; 
    double phi = cphi[i]; 
    double z   = cz[i];

    double emin = 1.;
    if(fabs(eta) > 3.) emin = 5.; 

    double r  = dR(eta_MC, phi_MC, eta, phi);
    if( r < searchR ) { // search for hottest cell in a big cone
      if(maxE < en && en > emin) {
    	maxE    = en;
	etaHot  = eta;
	phiHot  = phi;
	ietahot = ieta;
	iphihot = iphi;
      }
    }
      
    if (depth == 1) {
      map_depth1->Fill(double(ieta), double(iphi), en);
      profile_z1->Fill(double(ieta), z); 
    }
    if (depth == 2) {
      map_depth2->Fill(double(ieta), double(iphi), en);
      profile_z2->Fill(double(ieta), z); 
    }
    if (depth == 3) {
      map_depth3->Fill(double(ieta), double(iphi), en);
      profile_z3->Fill(double(ieta), z); 
    }
    if (depth == 4) {
      map_depth4->Fill(double(ieta), double(iphi), en);
      profile_z4->Fill(double(ieta), z); 
    }
    
    double cut = cutHB;  
    if (sub == 2) cut = cutHE;
    if (sub == 3) cut = cutHO;
    if (sub == 4){
      if(depth == 1) cut = cutHFL;
      else  cut = cutHFS;
    }

    if(en > cut ) {
      if (depth == 1)
	map_depth1_cuts->Fill(double(ieta), double(iphi), en);
      if (depth == 2)
	map_depth2_cuts->Fill(double(ieta), double(iphi), en);
      if (depth == 3)
	map_depth3_cuts->Fill(double(ieta), double(iphi), en);
      if (depth == 4)
	map_depth4_cuts->Fill(double(ieta), double(iphi), en);
    }

    if( r < partR ) {
      if (depth == 1) ehcal_coneMC_1 += en; 
      if (depth == 2) ehcal_coneMC_2 += en; 
      if (depth == 3) ehcal_coneMC_3 += en; 
      if (depth == 4) ehcal_coneMC_4 += en; 
    }
  }

  //    std::cout << "*** 5" << std::endl; 

  
  // IN ALL THE CASES : sum of rechits around MC particle = f(eta,phi) 
  
  map_econe_depth1->Fill(eta_MC, phi_MC, ehcal_coneMC_1);
  map_econe_depth2->Fill(eta_MC, phi_MC, ehcal_coneMC_2);
  map_econe_depth3->Fill(eta_MC, phi_MC, ehcal_coneMC_3);
  map_econe_depth4->Fill(eta_MC, phi_MC, ehcal_coneMC_4);


  //  NOISE ================================================================= 
  
  if (hcalselector_ == "noise") {
    for (unsigned int i = 0; i < cen.size(); i++) {
      
      int sub   = csub[i];
      int depth = cdepth[i];
      double en = cen[i]; 
      
      if (sub == 1) e_hb->Fill(en);
      if (sub == 2) e_he->Fill(en);  
      if (sub == 3) e_ho->Fill(en);  
      if (sub == 4) {
	if(depth == 1)  
	  e_hfl->Fill(en);  
	else 
	  e_hfs->Fill(en);  
      }
    }
  }

  //===========================================================================
  // SUBSYSTEMS,  
  //===========================================================================
  
  else {

    //    std::cout << "*** 6" << std::endl; 
    
    
    double clusEta = 999.;
    double clusPhi = 999.; 
    double clusEn  = 0.;
    
    double HcalCone_d1 = 0.;
    double HcalCone_d2 = 0.;
    double HcalCone_d3 = 0.;
    double HcalCone_d4 = 0.;

    int ietaMax1  =  9999;
    int ietaMax2  =  9999;
    int ietaMax3  =  9999;
    int ietaMax4  =  9999;
    double enMax1 = -9999.;
    double enMax2 = -9999.;
    double enMax3 = -9999.;
    double enMax4 = -9999.;

    /*
    std::cout << "*** point 5-1" << "  eta_MC, phi_MC    etaHot,  phiHot = "
	      << eta_MC  << ", " << phi_MC << "   "
	      << etaHot  << ", " << phiHot  
	      << std::endl;
    */

    //   CYCLE over cells ====================================================

    for (unsigned int i = 0; i < cen.size(); i++) {
      int sub    = csub[i];
      int depth  = cdepth[i];
      double eta = ceta[i]; 
      double phi = cphi[i]; 
      double en  = cen[i]; 
      double t   = ctime[i];
      int   ieta = cieta[i];

      double rhot = dR(etaHot, phiHot, eta, phi); 
      if(rhot < partR && en > 1.) { 
	clusEta = (clusEta * clusEn + eta * en)/(clusEn + en);
    	clusPhi = phi12(clusPhi, clusEn, phi, en); 
        clusEn += en;
      }

      nrechits++;	    
      eHcal += en;
      if(en > 1. ) nrechitsThresh++;

      double r    = dR(eta_MC, phi_MC, eta, phi);
      if( r < partR ){
        if(sub == 1)   eHcalConeHB += en;
        if(sub == 2)   eHcalConeHE += en;
        if(sub == 3)   eHcalConeHO += en;
        if(sub == 4) {
	  eHcalConeHF += en;
	  if (depth == 1) eHcalConeHFL += en;
	  else            eHcalConeHFS += en;
	}
	eHcalCone += en;
	nrechitsCone++;

	// search for most energetic cell at the given depth in the cone
        if(depth == 1) {
	  HcalCone_d1 += en;
	  if(enMax1 < en) {
	    enMax1   = en;
	    ietaMax1 = ieta;
	  }
	}
        if(depth == 2) {
	  HcalCone_d2 += en;
	  if(enMax2 < en) {
	    enMax2   = en;
	    ietaMax2 = ieta;
	  }
	}
        if(depth == 3) {
	  HcalCone_d3 += en;
	  if(enMax3 < en) {
	    enMax3   = en;
	    ietaMax3 = ieta;
	  }
	}
        if(depth == 4) {
	  HcalCone_d4 += en;
	  if(enMax4 < en) {
	    enMax4   = en;
	    ietaMax4 = ieta;
	  }
	}


      }
      
      if(sub == 1 && (subdet_ == 1 || subdet_ == 5)) {  
	meTimeHB->Fill(t);
	meRecHitsEnergyHB->Fill(en);
	meTE_HB->Fill( en, t);
	if(depth == 1)      meTE_HB1->Fill( en, t);
	else if(depth == 2) meTE_HB2->Fill( en, t);
	meTEprofileHB->Fill(en, t);
      }
      
      if(sub == 2 && (subdet_ == 2 || subdet_ == 5)) {  
	meTimeHE->Fill(t);
	meRecHitsEnergyHE->Fill(en);
	meTE_HE->Fill( en, t);
	if(depth == 1)      meTE_HE1->Fill( en, t);
	else if(depth == 2) meTE_HE2->Fill( en, t);
	meTEprofileHE->Fill(en, t);
      }

      if(sub == 4 && (subdet_ == 4 || subdet_ == 5)) {  
	  meTimeHF->Fill(t);
	  meTE_HF->Fill(en, t);
	  if(depth == 1) meTE_HFL->Fill( en, t);
	  else           meTE_HFS->Fill( en, t);
	  meTEprofileHF->Fill(en, t);
	  meRecHitsEnergyHF->Fill(en);	  
      }

      if(sub == 3 && (subdet_ == 3 || subdet_ == 5)) {  
	meTimeHO->Fill(t);
	meRecHitsEnergyHO->Fill(en);
	meTE_HO->Fill( en, t);
	meTEprofileHO->Fill(en, t);
      }
    }

    meEnConeEtaProfile_depth1->Fill(double(ietaMax1), HcalCone_d1);
    meEnConeEtaProfile_depth2->Fill(double(ietaMax2), HcalCone_d2);
    meEnConeEtaProfile_depth3->Fill(double(ietaMax3), HcalCone_d3);
    meEnConeEtaProfile_depth4->Fill(double(ietaMax4), HcalCone_d4);


    //   std::cout << "*** 7" << std::endl; 

    
    // Single particle samples ONLY !  ======================================
    // Fill up some histos for "integrated" subsustems. 
    
    if(etype_ == 1) {

      /*
      std::cout << "*** point 7-1" << "  eta_MC, phi_MC   clusEta, clusPhi = "
                << eta_MC  << ", " << phi_MC << "   "
		<< clusEta << ", " << clusPhi 
		<< std::endl;
      */    

      double phidev = dPhiWsign(clusPhi, phi_MC);
      meDeltaPhi->Fill(eta_MC, phidev);
      double etadev = clusEta - eta_MC;
      meDeltaEta->Fill(eta_MC, etadev);

      if(subdet_ == 1) {
	meSumRecHitsEnergyHB->Fill(eHcal);
	meSumRecHitsEnergyConeHB->Fill(eHcalConeHB);    
	meNumRecHitsConeHB->Fill(double(nrechitsCone));
	meNumRecHitsThreshHB->Fill(double(nrechitsThresh));
      }

      if(subdet_ == 2) {
        meSumRecHitsEnergyHE->Fill(eHcal);
	meSumRecHitsEnergyConeHE->Fill(eHcalConeHE);    
	meNumRecHitsConeHE->Fill(double(nrechitsCone));
	meNumRecHitsThreshHE->Fill(double(nrechitsThresh));
      }

      if(subdet_ == 3) {
	meSumRecHitsEnergyHO->Fill(eHcal);
	meSumRecHitsEnergyConeHO->Fill(eHcalConeHO);    
	meNumRecHitsConeHO->Fill(double(nrechitsCone));
	meNumRecHitsThreshHO->Fill(double(nrechitsThresh));
      }

      if(subdet_ == 4) {
        if(eHcalConeHF > eps ) {
	meSumRecHitsEnergyHF ->Fill(eHcal);
	meSumRecHitsEnergyConeHF ->Fill(eHcalConeHF);    
	meSumRecHitsEnergyConeHFL ->Fill(eHcalConeHFL);    
	meSumRecHitsEnergyConeHFS ->Fill(eHcalConeHFS);    
	meNumRecHitsConeHF->Fill(double(nrechitsCone));
	}
      }

      //     std::cout << "*** 8" << std::endl; 


      // Also combine with ECAL if needed 
      if(subdet_ == 1  && ecalselector_ == "yes") {
		
	/*
	std::cout << "*** point 8-1" 
		  << "  eEcalB " << eEcalB << "  eHcal " << eHcal
		  << "  eEcalCone " <<  eEcalCone << "  eHcalCone " 
		  << eHcalCone
		  << "  numrechitsEcal " <<  numrechitsEcal
		  << std::endl;
	
	*/

       	meEcalHcalEnergyHB->Fill(eEcalB+eHcal);
      	meEcalHcalEnergyConeHB->Fill(eEcalCone+eHcalCone);
      	meNumEcalRecHitsConeHB->Fill(double(numrechitsEcal));

      }

      if(subdet_ == 2  && ecalselector_ == "yes"){
	
	/*
	std::cout << "*** point 8-2a" 
		  << "  eEcalE " << eEcalE << "  eHcal " << eHcal
		  << "  eEcalCone " <<  eEcalCone << "  eHcalCone " 
		  << eHcalCone
		  << "  numrechitsEcal " <<  numrechitsEcal
		  << std::endl;
	*/

	meEcalHcalEnergyHE->Fill(eEcalE+eHcal);
	meEcalHcalEnergyConeHE->Fill(eEcalCone+eHcalCone);
	meNumEcalRecHitsConeHE->Fill(double(numrechitsEcal));


      } 

      // Banana plots finally
      if(subdet_ == 1 && ecalselector_ == "yes")
	meEnergyHcalVsEcalHB -> Fill(eEcalCone,eHcalCone);
      if(subdet_ == 2 && ecalselector_ == "yes") 
	meEnergyHcalVsEcalHE -> Fill(eEcalCone,eHcalCone);
    }
  }

  //   std::cout << "*** 9" << std::endl; 


  //===========================================================================
  // Getting SimHits
  //===========================================================================

  if(subdet_ != 0 && imc !=0 ) {  // not noise 

    double maxES = -9999.;
    double etaHotS = 1000.;
    double phiHotS = 1000.;
    
    edm::Handle<PCaloHitContainer> hcalHits;
    ev.getByLabel("g4SimHits","HcalHits",hcalHits);
    const PCaloHitContainer * SimHitResult = hcalHits.product () ;
    
    double enSimHits    = 0.;
    double enSimHitsHB  = 0.;
    double enSimHitsHE  = 0.;
    double enSimHitsHO  = 0.;
    double enSimHitsHF  = 0.;
    double enSimHitsHFL = 0.;
    double enSimHitsHFS = 0.;
    // sum of SimHits in the cone 
    
    for (std::vector<PCaloHit>::const_iterator SimHits = SimHitResult->begin () ; SimHits != SimHitResult->end(); ++SimHits) {
      HcalDetId cell(SimHits->id());
      int sub =  cell.subdet();
      const CaloCellGeometry* cellGeometry =
	geometry->getSubdetectorGeometry (cell)->getGeometry (cell) ;
      double etaS = cellGeometry->getPosition().eta () ;
      double phiS = cellGeometry->getPosition().phi () ;
      double en   = SimHits->energy();    

      double emin = 0.01;
      if(fabs(etaS) > 3.) emin = 1.;   

      double r  = dR(eta_MC, phi_MC, etaS, phiS);
      if( r < searchR ) { // search for hottest cell in a big cone
	if(maxES < en && en > emin ) {
	  maxES    = en;
	  etaHotS  = etaS;
	  phiHotS  = phiS;
	}
      }
       
      if ( r < partR ){ // just energy in the small cone
	enSimHits += en;
	if(sub == 1) enSimHitsHB += en; 
	if(sub == 2) enSimHitsHE += en; 
	if(sub == 3) enSimHitsHO += en; 
	if(sub == 4) {
	  enSimHitsHF += en;
	  int depth = cell.depth();
	  if(depth == 1) enSimHitsHFL += en;
	  else           enSimHitsHFS += en;
	} 
      }
    }


    // Second look over SimHits: cluster finding

    double clusEta = 999.;
    double clusPhi = 999.; 
    double clusEn  = 0.;

    for (std::vector<PCaloHit>::const_iterator SimHits = SimHitResult->begin () ; SimHits != SimHitResult->end(); ++SimHits) {
     HcalDetId cell(SimHits->id());

      const CaloCellGeometry* cellGeometry =
	geometry->getSubdetectorGeometry (cell)->getGeometry (cell) ;
      double etaS = cellGeometry->getPosition().eta () ;
      double phiS = cellGeometry->getPosition().phi () ;
      double en   =  SimHits->energy();    

      double emin = 0.01;
      if(fabs(etaS) > 3.) emin = 1.; 

      double rhot = dR(etaHotS, phiHotS, etaS, phiS); 
      if(rhot < partR && en > emin) { 
	clusEta = (clusEta * clusEn + etaS * en)/(clusEn + en);
    	clusPhi = phi12(clusPhi, clusEn, phiS, en); 
        clusEn += en;
      }
    }

    // SimHits cluster deviation from MC (eta, phi)
    if(etype_ == 1) {
      double phidev = dPhiWsign(clusPhi, phi_MC);
      meDeltaPhiS->Fill(eta_MC, phidev);
      double etadev = clusEta - eta_MC;
      meDeltaEtaS->Fill(eta_MC, etadev);
    }


    // Now some histos with SimHits
    
    if(subdet_ == 4 || subdet_ == 5) {
      if(eHcalConeHF > eps) {
      meRecHitSimHitHF->Fill( enSimHitsHF, eHcalConeHF );
      meRecHitSimHitProfileHF->Fill( enSimHitsHF, eHcalConeHF);
      
      meRecHitSimHitHFL->Fill( enSimHitsHFL, eHcalConeHFL );
      meRecHitSimHitProfileHFL->Fill( enSimHitsHFL, eHcalConeHFL);
      meRecHitSimHitHFS->Fill( enSimHitsHFS, eHcalConeHFS );
      meRecHitSimHitProfileHFS->Fill( enSimHitsHFS, eHcalConeHFS);       
      }
    }
    if(subdet_ == 1  || subdet_ == 5) { 
      meRecHitSimHitHB->Fill( enSimHitsHB,eHcalConeHB );
      meRecHitSimHitProfileHB->Fill( enSimHitsHB,eHcalConeHB);
    }
    if(subdet_ == 2  || subdet_ == 5) { 
      meRecHitSimHitHE->Fill( enSimHitsHE,eHcalConeHE );
      meRecHitSimHitProfileHE->Fill( enSimHitsHE,eHcalConeHE);
    }
    if(subdet_ == 3  || subdet_ == 5) { 
      meRecHitSimHitHO->Fill( enSimHitsHO,eHcalConeHO );
      meRecHitSimHitProfileHO->Fill( enSimHitsHO,eHcalConeHO);
    }

  }
}


///////////////////////////////////////////////////////////////////////////////
void HcalRecHitsValidation::fillRecHitsTmp(int subdet_, edm::Event const& ev){
  
  using namespace edm;
  
  
  // initialize data vectors
  csub.clear();
  cen.clear();
  ceta.clear();
  cphi.clear();
  ctime.clear();
  cieta.clear();
  ciphi.clear();
  cdepth.clear();


  if( subdet_ == 1 || subdet_ == 2  || subdet_ == 5 || subdet_ == 0) {
    
    //HBHE
    std::vector<edm::Handle<HBHERecHitCollection> > hbhecoll;
    ev.getManyByType(hbhecoll);
    std::vector<edm::Handle<HBHERecHitCollection> >::iterator i;
    
    for (i=hbhecoll.begin(); i!=hbhecoll.end(); i++) {
      for (HBHERecHitCollection::const_iterator j=(*i)->begin(); j!=(*i)->end(); j++) {
	HcalDetId cell(j->id());
	const CaloCellGeometry* cellGeometry =
	  geometry->getSubdetectorGeometry (cell)->getGeometry (cell) ;
	double eta  = cellGeometry->getPosition().eta () ;
	double phi  = cellGeometry->getPosition().phi () ;
        double zc   = cellGeometry->getPosition().z ();
	int sub     = cell.subdet();
	int depth   = cell.depth();
	int inteta  = cell.ieta();
	if(inteta > 0) inteta -= 1;
	int intphi  = cell.iphi()-1;
	double en   = j->energy();
	double t    = j->time();

	if((iz > 0 && eta > 0.) || (iz < 0 && eta <0.) || iz == 0) { 
	
	  csub.push_back(sub);
	  cen.push_back(en);
	  ceta.push_back(eta);
	  cphi.push_back(phi);
	  ctime.push_back(t);
	  cieta.push_back(inteta);
	  ciphi.push_back(intphi);
	  cdepth.push_back(depth);
	  cz.push_back(zc);
	}
      }
    }
  }

  if( subdet_ == 4 || subdet_ == 5 || subdet_ == 0) {

    //HF
    std::vector<edm::Handle<HFRecHitCollection> > hfcoll;
    ev.getManyByType(hfcoll);
    std::vector<edm::Handle<HFRecHitCollection> >::iterator ihf;
    for (ihf=hfcoll.begin(); ihf!=hfcoll.end(); ihf++) {      
      for (HFRecHitCollection::const_iterator j=(*ihf)->begin(); j!=(*ihf)->end(); j++) {
	HcalDetId cell(j->id());
	const CaloCellGeometry* cellGeometry =
	  geometry->getSubdetectorGeometry (cell)->getGeometry (cell) ;
	double eta   = cellGeometry->getPosition().eta () ;
	double phi   = cellGeometry->getPosition().phi () ;
        double zc     = cellGeometry->getPosition().z ();
	int sub      = cell.subdet();
	int depth    = cell.depth();
	int inteta   = cell.ieta();
	if(inteta > 0) inteta -= 1;
	int intphi   = cell.iphi()-1;
	double en    = j->energy();
	double t     = j->time();

	if((iz > 0 && eta > 0.) || (iz < 0 && eta <0.) || iz == 0) { 
	
	  csub.push_back(sub);
	  cen.push_back(en);
	  ceta.push_back(eta);
	  cphi.push_back(phi);
	  ctime.push_back(t);
	  cieta.push_back(inteta);
	  ciphi.push_back(intphi);
	  cdepth.push_back(depth);
	  cz.push_back(zc);
       
	}
      }
    }
  }

  //HO

  if( subdet_ == 3 || subdet_ == 5 || subdet_ == 0) {
  
    std::vector<edm::Handle<HORecHitCollection> > hocoll;
    ev.getManyByType(hocoll);
    std::vector<edm::Handle<HORecHitCollection> >::iterator iho;
    
    for (iho=hocoll.begin(); iho!=hocoll.end(); iho++) {
      for (HORecHitCollection::const_iterator j=(*iho)->begin(); j!=(*iho)->end(); j++) {
	HcalDetId cell(j->id());
	const CaloCellGeometry* cellGeometry =
	  geometry->getSubdetectorGeometry (cell)->getGeometry (cell) ;
	double eta   = cellGeometry->getPosition().eta () ;
	double phi   = cellGeometry->getPosition().phi () ;
        double zc    = cellGeometry->getPosition().z ();
	int sub      = cell.subdet();
	int depth    = cell.depth();
	int inteta   = cell.ieta();
	if(inteta > 0) inteta -= 1;
	int intphi   = cell.iphi()-1;
	double t     = j->time();
	double en    = j->energy();
	
	if((iz > 0 && eta > 0.) || (iz < 0 && eta <0.) || iz == 0) { 
	  csub.push_back(sub);
	  cen.push_back(en);
	  ceta.push_back(eta);
	  cphi.push_back(phi);
	  ctime.push_back(t);
	  cieta.push_back(inteta);
	  ciphi.push_back(intphi);
	  cdepth.push_back(depth);
	  cz.push_back(zc);
	}
      }
    }
  }      
  
}
double HcalRecHitsValidation::dR(double eta1, double phi1, double eta2, double phi2) { 
  double PI = 3.1415926535898;
  double deltaphi= phi1 - phi2;
  if( phi2 > phi1 ) { deltaphi= phi2 - phi1;}
  if(deltaphi > PI) { deltaphi = 2.*PI - deltaphi;}
  double deltaeta = eta2 - eta1;
  double tmp = sqrt(deltaeta* deltaeta + deltaphi*deltaphi);
  return tmp;
}

double HcalRecHitsValidation::phi12(double phi1, double en1, double phi2, double en2) {
  // weighted mean value of phi1 and phi2
  
  double tmp;
  double PI = 3.1415926535898;
  double a1 = phi1; double a2  = phi2;

  if( a1 > 0.5*PI  && a2 < 0.) a2 += 2*PI; 
  if( a2 > 0.5*PI  && a1 < 0.) a1 += 2*PI; 
  tmp = (a1 * en1 + a2 * en2)/(en1 + en2);
  if(tmp > PI) tmp -= 2.*PI; 
 
  return tmp;

}

double HcalRecHitsValidation::dPhiWsign(double phi1, double phi2) {
  // clockwise      phi2 w.r.t phi1 means "+" phi distance
  // anti-clockwise phi2 w.r.t phi1 means "-" phi distance 

  double PI = 3.1415926535898;
  double a1 = phi1; double a2  = phi2;
  double tmp =  a2 - a1;
  if( a1*a2 < 0.) {
    if(a1 > 0.5 * PI)  tmp += 2.*PI;
    if(a2 > 0.5 * PI)  tmp -= 2.*PI;
  }
  return tmp;

}

#include "FWCore/PluginManager/interface/ModuleDef.h"
#include "FWCore/Framework/interface/MakerMacros.h"

DEFINE_SEAL_MODULE();
DEFINE_ANOTHER_FWK_MODULE(HcalRecHitsValidation);

