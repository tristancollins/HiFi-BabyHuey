
*****************************************************************
*
* Tube library based on uTracer data, fitted with ExtractModel.
*
* Version: Jul-30-2017
*
* **** IMPORTANT ****
* This library has XXXX_triode models (pentode strapped as triode) with corrected mu
* Versions prior to May-17-2015 still have XXXX_triode models with mu identical 
* to the pentode mu, which is incorrect
*
* Data traced by Derk Reefman, except mentioned otherwise; contributors are:
* Ale Moglia (valves@bartola.co.uk)
* Juha Niinikoski (juha.niinikoski@sitecno.fi)
* Anders Magnusson (ragge@ludd.ltu.se)
* Richard Zajkowski (richard@zajkowski.net)
*
* Models created with ExtractModel
*
*
* For all tubes, the .SUBCKT name is the tube model name. The EL34 for example is found as:
* .SUBCKT EL34 1 2 3 4
* For pentode tubes, there is a separate model describing the triode-strapped tube, and can be found as
* the tube name, with a suffix _triode added. The EL34 triode strapped can thus be found as:
* .SUBCKT EL34_triode 1 2 3
*
* For combination tubes, such as the ECL86, the tube described is added to the tube name. The pentode 
* section of the ECL86 for example can befound as .SUBCKT ECL86_L 1 2 3 4. Likewise the triode section
* is provided as .SUBCKT ECL86_C 1 2 3. Exceptions to this convention are diodes in a combination tube,
* which are indicated with a suffix _D (or _D1 and _D2 incase of different diodes)
* For American types this may lead to a combination of European-style suffices. The pentode section of
* the 6GH8 for example can be found as the 6GH8_F.
*
* For pentodes where the third grid is modelled separately, the suffix _g3 is added to the tube name.
* For example, the model for the EF80 tube can be found as EF80_g3.
*
* Note that were possible, similar tubes types (e.g. ECL86 and PCL86) reference each other. Also note that
* different filament letters P/U/E do not mean tubes are identical always! The PL84 for example is a VERY
* different tube from a EL84!
*
* Capacitances are from datasheets available at Frank's Electron tube Pages (http://www.tubedata.org/). 
* If a capacitance is set to 0.0, it indicates that it is not included in the model. 
* It does not mean it is actually zero!
*
* European type first in alphabetical/numerical order
* American types next in numerical/alphabetical order
* Russian types last in numerical/alphabetical order
*
****************************************************

****************************************************                            
****************************************************
.SUBCKT AZ1 1 2 3; A1 A2 C;
*      Extract V1.998
* Model created: 22-Feb-2015
X1 1 3 DiodeK  EX=1.452 k = 2115.2 eps=   -.8
+ CCP=0.0P  ;
X2 2 3 DiodeK  EX=1.452 k = 2115.2 eps=   -.8
+ CCP=0.0P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT AZ4 1 2 3; A1 A2 C;
*      Extract V1.998
* Model created: 24-Feb-2015
*
* Thanks to Anders Magnusson (ragge@ludd.ltu.se)
*
* Philips AZ4 with readings slightly better than specs.
X1 1 3 DiodeK  EX=1.346 k =  701.3 eps=    .6
+ CCP=0.0P  ;
X2 2 3 DiodeK  EX=1.346 k =  701.3 eps=    .6
+ CCP=0.0P  ;
.ENDS
****************************************************                            
****************************************************                            
.SUBCKT AZ11 1 2 3; A1 A2 C;                                                      
X1 1 2 3 AZ1
.ENDS                                                                           
****************************************************                            
****************************************************                            
.SUBCKT AZ12 1 2 3; A1 A2 C;                                                      
X1 1 2 3 AZ4
.ENDS                                                                           
****************************************************                            
****************************************************                            
.SUBCKT AZ31 1 2 3; A1 A2 C;                                                      
X1 1 2 3 AZ1
.ENDS                                                                           
****************************************************                            
****************************************************
.SUBCKT CV378 1 2 3; A1 A2 C;
*      Extract V1.995
* Model created:  7-Dec-2014
X1 1 3 DiodeK  EX=1.224 k =  149.6 eps=   -.3
+ CCP=0.0P  ;
X2 2 3 DiodeK  EX=1.224 k =  149.6 eps=   -.3
+ CCP=0.0P  ;
.ENDS
****************************************************                            
****************************************************                            
.SUBCKT E80CF_F 1 2 3 4 ; A G2 G1 C;                                         
*      Extract V1.993
* Model created:  4-Oct-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 4 BTetrodeD  MU= 44.47 EX=1.482 kG1= 243.2 KP= 212.2 kVB =     .0 kG2= 1124.5
+Sc=.60E+00 ap=  .100 w=    11. nu=   .00 lam=    35.5
+ Ookg1mOokG2=.322E-02 Aokg1=.21E-06 alkg1palskg2=.322E-02 be=  .183 als=  3.18 RGI=2000
+ CCG1=5.6P CCG2=0.0P  CPG1 = 0.025p CG1G2 = 0.0p CCP=3.4P  ;                                    
.ENDS                                                                           
****************************************************                            
.SUBCKT E80CF_F_triode 1 2 3; A G C;                                             
*      Extract V1.993
* Model created:  4-Oct-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU= 44.47 EX=1.491 KG1= 243.2 KP= 212.2 KVB=    0. RGI=2000
+ CCG=5.5P  CGP=0.0P CCP=3.8P  ;                                                
.ENDS                                                                           
****************************************************                            
.SUBCKT E80CF_C 1 2 3; A G C;                                                    
*      Extract V1.993
* Model created:  4-Oct-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU= 20.86 EX=1.385 KG1= 426.6 KP=  79.3 KVB=  345. RGI=2000
+ CCG=2.5P  CGP=1.5P CCP=1.5P  ;                                                
.ENDS                                                                           
****************************************************
****************************************************
.SUBCKT E90CC 1 2 3; A G C;
*      Extract V1.992
* Model created: 21-Sep-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU= 31.30 EX=1.393 KG1= 256.8 KP= 115.9 KVB=  785. RGI=2000
+ CCG=3.4P  CGP=3.2P CCP=0.4P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT E91H 1 2 3 4 5; A G3 G2G4 G1 C;
*      Extract V1.950
* Model created: 20-Apr-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 4 5 HepthodeD MU= 19.3 MU3=.6E+05 EX=1.328 kG1= 353.5 KP=  55.1 kVB =   594.1 kG2=  361.6
+ MUp= 14.7 EXX= .124 kG1p=    .1 KPp= 177.5 kVBp =      .0
+ Ookg1mOokG2=.64E-04 Aokg1=.12E-07 al= .14E-01 alkg1palskg2=.64E-04 be=   .19 als=   .01 RGI=2000
+ CCG1=0.0P  CCG3 = 0.0p CPG1 = 0.0p CG1G3 = 0.0p CCP=0.0P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT E92CC 1 2 3; A G C;
*      Extract V1.036
* Model created:  2-Feb-2014
X1 1 2 3 TriodeK MU= 56.17 EX=1.319 KG1= 179.3 KP= 145.8 KVB= 1718. RGI=2000
+ CCG=3.1P  CGP=2.2P CCP=0.32P  ;
.ENDS
****************************************************                            
****************************************************
.SUBCKT EABC80_C 1 2 3; A G C;
*      Extract V1.036
* Model created:  9-Feb-2014
X1 1 2 3 TriodeK MU= 77.40 EX=1.347 KG1=1059.8 KP= 666.3 KVB=  936. RGI=2000
+ CCG=1.9P  CGP=2.0P CCP=1.4P  ;
.ENDS
****************************************************
.SUBCKT EABC80_D1 1 2; A C;
*      Extract V1.037
* Model created:  9-Feb-2014
X1 1 2 DiodeK  EX=1.180 k =22241.5 eps=    .1
+ CCP=0.8P  ;
.ENDS
****************************************************
.SUBCKT EABC80_D2 1 2; A C;
* Diode D3 is equivalent
*      Extract V1.037
* Model created:  9-Feb-2014
X1 1 2 DiodeK  EX= .984 k =  264.9 eps=   -.4
+ CCP=4.8P  ;
.ENDS
****************************************************                            
****************************************************                            
.SUBCKT EC86 1 2 3; A G C;                                                      
* ExtractModel V .998
* Model created: 07-Dec-13                                                      
X1 1 2 3 PC86                                                
.ENDS                                                                           
****************************************************                            
****************************************************
.SUBCKT EC88 1 2 3; A G C;
*      Extract V1.993
* Model created:  2-Dec-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU= 90.27 EX=1.233 KG1= 178.7 KP= 644.3 KVB= 5908. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;
.ENDS
****************************************************                            
****************************************************                            
.SUBCKT EC91 1 2 3; A G C;                                                      
* ExtractModel V .998
* Model created: 08-Dec-13                                                      
X1 1 2 3 TriodeK MU= 81.62 EX=1.441 KG1= 212.3 KP= 457.5 KVB= 9233. RGI=2000
+ CCG=8.5P  CGP=2.5P CCP=0.2P  ;                                                
.ENDS                                                                           
****************************************************                            
****************************************************
.SUBCKT ECC40 1 2 3; A G C;
*      Extract V1.993
* Model created: 16-Nov-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU= 34.86 EX=1.232 KG1= 420.2 KP= 177.7 KVB= 1010. RGI=2000
+ CCG=2.8P  CGP=2.7P CCP=1.1P  ;
.ENDS
****************************************************                            
****************************************************                            
.SUBCKT ECC81 1 2 3; A G C;                                                     
* ExtractModel V .998
* Model created: 08-Dec-13                                                      
X1 1 2 3 TriodeK MU= 63.24 EX=1.338 KG1= 306.7 KP= 208.5 KVB= 2363. RGI=2000
+ CCG=2.2P  CGP=1.6P CCP=0.20P  ;                                                
.ENDS                                                                           
****************************************************                            
****************************************************                            
.SUBCKT ECC82 1 2 3; A G C;                                                     
* ExtractModel V .998
* Model created: 09-Dec-13                                                      
X1 1 2 3 TriodeK MU= 20.73 EX=1.350 KG1= 751.3 KP=  85.3 KVB=  992. RGI=2000
+ CCG=1.8P  CGP=1.6P CCP=0.5P  ;                                                
.ENDS                                                                           
****************************************************                            
****************************************************                            
.SUBCKT ECC83 1 2 3; A G C;                                                     
* ExtractModel V .998
* Model created: 09-Dec-13                                                      
X1 1 2 3 TriodeK MU=108.93 EX= .988 KG1= 389.8 KP= 677.7 KVB=10751. RGI=2000
+ CCG=1.6P  CGP=1.6P CCP=0.33P  ;                                                
.ENDS                                                                           
****************************************************                            
****************************************************                            
.SUBCKT ECC85 1 2 3; A G C;                                                     
* ExtractModel V .998
* Model created: 08-Dec-13                                                      
X1 1 2 3 TriodeK MU= 94.04 EX=1.148 KG1= 119.8 KP= 230.9 KVB= 3805. RGI=2000
+ CCG=3.1P  CGP=1.5P CCP=0.18P  ;                                                
.ENDS                                                                           
****************************************************
****************************************************                            
.SUBCKT ECC88 1 2 3; A G C;                                                     
* ExtractModel V .998
* Model created: 09-Dec-13                                                      
X1 1 2 3 TriodeK MU= 34.63 EX=1.090 KG1= 139.8 KP= 288.0 KVB= 1209. RGI=2000
+ CCG=3.3P  CGP=1.4P CCP=1.8P  ;                                                
.ENDS                                                                                                      
****************************************************                            
****************************************************
.SUBCKT ECC91 1 2 3; A G C;
*      Extract V1.036
* Model created:  2-Feb-2014
X1 1 2 3 TriodeK MU= 43.82 EX=1.157 KG1= 156.4 KP= 144.8 KVB= 4141. RGI=2000
+ CCG=2.0P  CGP=1.6P CCP=0.4P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT ECC99 1 2 3; A G C;
*      Extract V1.999
* Model created: 10-Jul-2015
*
* Tubes contributed by Ray Waters
*
X1 1 2 3 TriodeK MU= 24.22 EX=1.635 KG1= 245.0 KP= 139.9 KVB=    0. RGI=2000
+ CCG=5.8P  CGP=5.1P CCP=0.9P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT ECF80_F 1 2 3 4
X1 1 2 3 4 PCF80_F
.ENDS                            
****************************************************
.SUBCKT ECF80_C 1 2 3
X1 1 2 3 PCF80_C 
.ENDS                            
****************************************************                            
****************************************************
.SUBCKT ECH4H 1 2 3 4 5; A G3 G2G4 G1 C;
*      Extract V1.998
* Model created: 23-Mar-2015
*
* Thanks to Anders Magnusson (ragge@ludd.ltu.se)
*
* Valvo ECH4 with readings very close to specs.
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 4 5 HepthodeD MU= 38.0 MU3=.4E+06 EX=1.302 kG1=189.4 KP=57.0 kVB=896.5 kG2=285.7
+ MUp= 29.2 EXX= .089 kG1p=1. KPp=160.0 kVBp =.0
+ Ookg1mOokG2=.18E-02 Aokg1=.10E-10 al=-.18E-01 alkg1palskg2=.18E-02 be=.12 als=.54 RGI=2000
+ CCG1=6.5P  CCG3=8.0p CPG1 = 0.0002p CG1G3 = 0.3p CCP=8.0P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT ECH4T 1 2 3; A G C;
*      Extract V1.995
* Model created: 14-Dec-2014
*
* Thanks to Anders Magnusson (ragge@ludd.ltu.se)
*
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU= 30.07 EX=1.354 KG1= 591.1 KP=  51.5 KVB=  129. RGI=2000
+ CCG=3.8P  CGP=1.1P CCP=3.1P  ;
.ENDS
****************************************************
****************************************************

.SUBCKT ECH21_H 1 2 3 4 5; A G3 G2G4 G1 C;
*      Extract V1.996
* Model created: 20-Dec-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 4 5 HepthodeD MU= 26.7 MU3=.4E+05 EX=1.273 kG1= 333.9 KP=  64.0 kVB =  1597.3 kG2=  796.3
+ MUp= 16.0 EXX= .215 kG1p=    2. KPp=  182.6 kVBp =  5161.0
+ Ookg1mOokG2=.13E-02 Aokg1= .12E-11 al= .82E-01 alkg1palskg2=.13E-02 be=   .15 als=   .90 RGI=2000
+ CCG1=6.5P  CCG3 = 8.0p CPG1 = 0.002p CG1G3 = 0.3p CCP=8.0P  ;
.ENDS
****************************************************
.SUBCKT ECH21_C 1 2 3; A G C;
*      Extract V1.996
* Model created: 20-Dec-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU= 29.40 EX=1.174 KG1=1101.5 KP=  82.4 KVB=   54. RGI=2000
+ CCG=3.8P  CGP=1.1P CCP=3.1P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT ECH81_H 1 2 3 4 5; A G3 G2G4 G1 C;
*      Extract V1.930
* Model created:  6-Apr-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 4 5 HepthodeD MU= 35.8 MU3=.4E+02 EX=1.467 kG1= 256.8 KP=  46.3 kVB =  2108.1 kG2= 1655.6
+ MUp=  9.6 EXX= .175 kG1p=   2.4 KPp= 189.3 kVBp =   971.9
+ Ookg1mOokG2=.33E-02 Aokg1=.60E-11 al= .41E-01 alkg1palskg2=.33E-02 be=   .12 als=  5.18 RGI=2000
+ CCG1=4.8P  CCG3 = 6.0p CPG1 = 0.006p CG1G3 = 0.3p CCP=7.9P  ;
.ENDS
****************************************************
.SUBCKT ECH81_C 1 2 3; A G C;
*      Extract V1.900
* Model created: 16-Mar-2014
X1 1 2 3 TriodeK MU= 22.58 EX=1.453 KG1= 784.7 KP=  72.7 KVB= 1322. RGI=2000
+ CCG=2.6P  CGP=1.0P CCP=2.1P  ;
.ENDS
****************************************************   
****************************************************
.SUBCKT ECH83_H 1 2 3 4 5; A G3 G2G4 G1 C;
*      Extract V1.910
* Model created: 22-Mar-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 4 5 HepthodeD MU= 32.7 MU3=.4E+05 EX=1.267 kG1= 339.1 KP=  46.2 kVB =  1393.0 kG2=  820.7
+ MUp= 11.6 EXX= .175 kG1p=   1.4 KPp= 171.0 kVBp =  1595.0
+ Ookg1mOokG2=.17E-02 Aokg1=.19E-12 al=-.14E-01 alkg1palskg2=.17E-02 be=   .17 als=  1.46 RGI=2000
+ CCG1=4.8P  CCG3 = 6.0p CPG1 = 0.012p CG1G3 = 0.3p CCP=7.9P  ;
.ENDS
****************************************************
.SUBCKT ECH83_C 1 2 3; A G C;
*      Extract V1.910
* Model created: 22-Mar-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU= 23.93 EX=1.027 KG1= 462.9 KP=  62.9 KVB=  605. RGI=2000
+ CCG=2.6P  CGP=1.0P CCP=2.1P  ;
.ENDS
****************************************************                            
****************************************************
.SUBCKT ECL80_L 1 2 3 4 ; A G2 G1 C;
*      Extract V1.999
* Model created:  9-May-2015
*
X1 1 2 3 4 BTetrodeD  MU= 17.14 EX=1.318 kG1= 341.9 KP=  43.4 kVB =  816.8 kG2= 2405.5
+Sc=.13E-01 ap=  .100 w=    33. nu=   .62 lam=     4.1
+ Ookg1mOokG2=.251E-02 Aokg1=.44E-06 alkg1palskg2=.251E-02 be=  .136 als=  5.10 RGI=2000
+ CCG1=4.3P  CCG2 = 0.0p CPG1 = 0.2p  CG1G2 = 0.0p CCP=4.8P  ;
.ENDS
****************************************************
.SUBCKT ECL80_L_triode 1 2 3; A G C;
*      Extract V1.999
* Model created:  9-May-2015
*
X1 1 2 3 TriodeK MU= 17.14 EX=1.340 KG1= 341.9 KP=  43.4 KVB=  817. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;
.ENDS
****************************************************
.SUBCKT ECL80_C 1 2 3; A G C;
*      Extract V1.999
* Model created:  9-May-2015
*
X1 1 2 3 TriodeK MU= 29.17 EX=1.370 KG1= 728.7 KP=  43.0 KVB=  481. RGI=2000
+ CCG=2.1P  CGP=0.9P CCP=0.8P  ;
.ENDS
****************************************************                            
****************************************************                            
.SUBCKT ECL82_C 1 2 3; A G C;                                                    
* ExtractModel V .998
* Model created: 10-Dec-13                                                      
X1 1 2 3 TriodeK MU= 80.60 EX=1.022 KG1= 287.2 KP= 428.3 KVB= 5341. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;                                                
.ENDS                                                                           
****************************************************                            
.SUBCKT ECL82_L 1 2 3 4 ; A G2 G1 C;                                         
* ExtractModel V .999
* Model created: 12-Dec-13                                                      
X1 1 2 3 4 BTetrodeD  MU= 11.49 EX=1.264 kG1= 181.9 KP=  53.9 kVB = 2066.3 kG2=  991.9
+Sc=.30E-01 ap=  .016 w=    55. nu=  5.08 lam=2025.94
+ Ookg1mOokG2=.449E-02 Aokg1=.61E-05 alkg1palskg2=.449E-02 be=  .097 als=  2.92 RGI=2000
+ CCG1=0.0P CCG2=0.0P  CPG1 = 0.00p CG1G2 = 0.0p CCP=0.0P  ;                                    
.ENDS                                                                          
****************************************************                            
.SUBCKT ECL82_L_triode 1 2 3; A G C;                                             
* ExtractModel V .999
* Model created: 12-Dec-13                                                      
X1 1 2 3 TriodeK MU= 11.49 EX=1.3809 KG1= 181.9 KP=  53.9 KVB= 2066. RGI=2000
+ CCG=0.0P  CPG1 = 0.0p CGP=0.0P CCP=0.0P  ;                                    
.ENDS                                                                           
****************************************************                            
****************************************************                            
.SUBCKT ECL84_C 1 2 3; A G C;                                                    
X1 1 2 3 PCL84_C
.ENDS                                                                           
****************************************************                            
.SUBCKT ECL84_L 1 2 3 4 ; A G2 G1 C;                                         
X1 1 2 3 4 PCL84_L
.ENDS                                                                           
****************************************************                            
.SUBCKT ECL84_L_triode 1 2 3; A G C;                                             
X1 1 2 3 PCL84_L_triode
.ENDS                                                                           
****************************************************                            
****************************************************                            
.SUBCKT ECL86_C 1 2 3; A G C;                                                    
X1 1 2 3 PCL86_C
.ENDS                                                                           
****************************************************                            
.SUBCKT ECL86_L 1 2 3 4 ; A G2 G1 C;                                         
X1 1 2 3 4 PCL86_L
.ENDS                                                                           
****************************************************                            
.SUBCKT ECL86_L_triode 1 2 3; A G C;                                             
X1 1 2 3 PCL86_L_triode
.ENDS                                                                           
****************************************************
****************************************************

.SUBCKT EF37 1 2 3 4 ; A G2 G1 C;
*      Extract V1.999
* Model created: 22-Mar-2015
*
X1 1 2 3 4 PenthodeD  MU= 29.5 EX=1.266 kG1= 465.3 KP= 136.4 kVB =  1701.0 kG2= 2259.4
+ Ookg1mOokG2=.17E-02 Aokg1=.18E-15 alkg1palskg2=.17E-02 be=   .15 als=  3.85 RGI=2000
+ CCG1=5.5P  CCG2 = 0.0p CPG1 = 0.02p CG1G2 = 0.0p CCP=8.5P  ;
.ENDS
****************************************************
.SUBCKT EF37_triode 1 2 3; A G C;
*      Extract V1.999
* Model created: 22-Mar-2015
*
X1 1 2 3 TriodeK MU= 29.48 EX=1.266 KG1= 465.3 KP= 136.4 KVB= 1701. RGI=2000
+ CCG=5.5P  CGP=0.0P CCP=0.0P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT EF80 1 2 3 4 ; A G2 G1 C;                                           
* ExtractModel V .997
* Model created: 07-Dec-13                                                      
X1 1 2 3 4 PenthodeDE  MU= 54.7 EX=1.202 kG1= 136.4 KP= 340.3 kVB =  4670.0 kG2=  584.2
+ Ookg1mOokG2=.56E-02 Aokg1=.23E-05 alkg1palskg2=.56E-02 be=  .054 als=  3.09 RGI=2000
+ CCG1=7.5P CCG2=5.4P  CPG1 = 0.007p CG1G2 = 2.6p CCP=0.012P  ;                                    
.ENDS
****************************************************                            
.SUBCKT EF80_triode 1 2 3; A G C;                                               
* ExtractModel V .997
* Model created: 07-Dec-13                                                      
X1 1 2 3 TriodeK MU= 54.7 EX=1.268 KG1= 136.4 KP= 340.3 KVB= 4670. RGI=2000
+ CCG=7.5P  CGP=2.6P CCP=0.0P  ;                                                
.ENDS                                                                           
****************************************************
.SUBCKT EF80_g3 1 2 3 4 5; A G3 G2 G1 C;
*      Extract V1.950
* Model created: 20-Apr-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 4 5 Penthodeg3DE MU= 48.9 MU3=.2E+03 EX=1.386 kG1= 224.6 KP= 762.4 kVB = 11076.4 kG2= 1079.4
+ MUp=  5.5 EXX=1.882 kG1p= 462.2 V0=  35.2
+ Ookg1mOokG2=.35E-02 Aokg1=.74E-06 al=0.67E-01 alkg1palskg2=.35E-02 be=  0.06 als=  3.49 RGI=2000
+ CCG1=7.5P  CCG2 = 5.4p CCG3 = 0.0p CPG1 = 0.007p  CG1G2 = 2.6p CG1G3 = 0.0p CCP=0.012P  ;
.ENDS
****************************************************                            
****************************************************
.SUBCKT EF85 1 2 3 4 ; A G2 G1 C;
*      Extract V3.000
* Model created: 20-Jan-2016
*
X1 1 2 3 4 PenthodeVDE  MU= 28.8 EX=1.247 kG1= 204.8 KP= 142.1 kVB =    69.6 kG2=  823.6
+ MUb=  7.6 EXb=0.896 svar= 0.047
+ Ookg1mOokG2=.37E-02 Aokg1=.14E-05 alkg1palskg2=.37E-02 be= 0.080 als=  2.57 RGI=2000
+ CCG1=6.9P  CCG2 = 0.0p CPG1 = 0.007p  CG1G2 = 0.0p CCP=3.2P  ;
.ENDS
****************************************************                            
****************************************************                            
.SUBCKT EF86 1 2 3 4 ; A G2 G1 C;                                           
*      Extract V1.992
* Model created:  7-Sep-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 4 PenthodeD  MU= 40.8 EX=1.327 kG1= 675.8 KP= 350.7 kVB =  1886.8 kG2= 4089.6
+ Ookg1mOokG2=.12E-02 Aokg1=.88E-07 alkg1palskg2=.12E-02 be=   .28 als=  4.24 RGI=2000
+ CCG1=0.0P CCG2=0.0P  CPG1 = 0.0p CG1G2 = 0.0p CCP=0.0P  ;                                    
.ENDS                                                                           
****************************************************                            
.SUBCKT EF86_triode 1 2 3; A G C;                                               
*      Extract V1.992
* Model created:  7-Sep-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU= 40.83 EX=1.339 KG1= 675.8 KP= 350.7 KVB= 1887. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;                                                
.ENDS                                                                           
****************************************************                            
****************************************************
.SUBCKT EF89 1 2 3 4 ; A G2 G1 C;
*      Extract V3.000
* Model created: 21-Jan-2016
*
X1 1 2 3 4 PenthodeVDE  MU= 25.0 EX=1.418 kG1= 328.3 KP=  58.8 kVB =     0.0 kG2= 1199.3
+ MUb=  7.8 EXb=0.978 svar= 0.068
+ Ookg1mOokG2=.22E-02 Aokg1=.36E-06 alkg1palskg2=.22E-02 be= 0.122 als=  2.07 RGI=2000
+ CCG1=5.5P  CCG2 = 0.0p CPG1 = 0.002p  CG1G2 = 0.0p CCP=5.1P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT EF91 1 2 3 4 ; A G2 G1 C;
*      Extract V1.950
* Model created: 20-Apr-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 4 PenthodeDE  MU= 72.4 EX=1.288 kG1= 149.7 KP= 262.4 kVB =  2760.2 kG2=  641.0
+ Ookg1mOokG2=.51E-02 Aokg1=.19E-05 alkg1palskg2=.51E-02 be=  .057 als=  3.04 RGI=2000
+ CCG1=7.3P  CCG2 = 0.0p CPG1 = 0.01p  CG1G2 = 0.0p CCP=3.4P  ;
.ENDS
****************************************************
.SUBCKT EF91_triode 1 2 3; A G C;
*      Extract V1.950
* Model created: 20-Apr-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU= 72.44 EX=1.3568 KG1= 149.7 KP= 262.4 KVB= 2760. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;
.ENDS
****************************************************                            
****************************************************
.SUBCKT EF184 1 2 3 4 ; A G2 G1 C;
*      Extract V1.993
* Model created:  2-Dec-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 4 BTetrodeD  MU= 75.12 EX=1.269 kG1=  55.4 KP= 519.6 kVB = 6044.0 kG2=  207.0
+Sc=.46E+00 ap=  .100 w=     3. nu=   .00 lam=  6715.1
+ Ookg1mOokG2=.132E-01 Aokg1=.86E-10 alkg1palskg2=.132E-01 be=  .144 als=  2.53 RGI=2000
+ CCG1=0.0P  CCG2 = 0.0p CPG1 = 0.0p  CG1G2 = 0.0p CCP=0.0P  ;
.ENDS
****************************************************
.SUBCKT EF184_triode 1 2 3; A G C;
*      Extract V1.993
* Model created:  2-Dec-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU= 75.12 EX=1.269 KG1=  55.4 KP= 519.6 KVB= 6044. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;
.ENDS
****************************************************                            
****************************************************
.SUBCKT EH90 1 2 3 4 5; A G3 G2G4 G1 C;
*      Extract V1.995
* Model created: 22-Mar-2015
*
* Thanks to Anders Magnusson (ragge@ludd.ltu.se)
*
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 4 5 HepthodeD MU= 34.7 MU3=.7E+06 EX=1.243 kG1= 144.0 KP=  46.3 kVB = 841.4 kG2=  169.5
+ MUp= 47.9 EXX= .118 kG1p=    .4 KPp=  271.4 kVBp =      .0
+ Ookg1mOokG2=.10E-02 Aokg1=.12E-05 al=-.22E-01 alkg1palskg2=.10E-02 be=   .20 als=   .20 RGI=2000
+ CCG1=5.5P  CCG3 = 7.0p CPG1 = 0.07p CG1G3 = 0.22p CCP=7.5P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT EK90 1 2 3 4 5; A G3 G2G4 G1 C;
*      Extract V1.995
* Model created: 22-Mar-2015
*
* Thanks to Anders Magnusson (ragge@ludd.ltu.se)
*
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 4 5 HepthodeD MU=21.7 MU3=.8E+02 EX=1.742 kG1=673.3 KP=48.5 kVB =.0 kG2=746.5
+ MUp=112.9 EXX= .041 kG1p=    .3 KPp=  517.5 kVBp =    10.3
+ Ookg1mOokG2=.15E-03 Aokg1=.18E-06 al= .59E-03 alkg1palskg2=.15E-03 be=.22 als=.11 RGI=2000
+ CCG1=5.5P  CCG3 = 7.0p CPG1 = 0.1p CG1G3 = 0.15p CCP=8.0P  ;
.ENDS
****************************************************
****************************************************                            
.SUBCKT EL34 1 2 3 4 ; A G2 G1 C;                                           
* ExtractModel V1.000
* Model created: 15-Dec-13                                                      
X1 1 2 3 4 BTetrodeD  MU= 12.50 EX=1.363 kG1= 217.7 KP=  50.5 kVB = 1282.7 kG2= 1950.2
+Sc=.22E-01 ap=  .033 w=    64. nu=  2.91 lam=   4.23
+ Ookg1mOokG2=.408E-02 Aokg1=.16E-05 alkg1palskg2=.408E-02 be=  .105 als=  6.09 RGI=2000
+ CCG1=15.4P CCG2=0.0P  CPG1 = 1.1p CG1G2 = 0.0p CCP=8.4P  ;                                    
.ENDS                                                                           
****************************************************                            
.SUBCKT EL34_triode 1 2 3; A G C;                                               
* ExtractModel V1.000
* Model created: 15-Dec-13                                                      
X1 1 2 3 TriodeK MU= 12.50 EX=1.4 KG1= 217.7 KP=  50.5 KVB= 1283. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;                                                
.ENDS                                                                           
****************************************************                            
****************************************************                            
.SUBCKT EL41 1 2 3 4 ; A G2 G1 C;                                           
* ExtractModel V1.010
* Model created: 22-Dec-13                                                      
X1 1 2 3 4 BTetrodeD  MU= 25.06 EX=1.264 kG1= 172.1 KP= 133.6 kVB = 1952.2 kG2= 1327.5
+Sc=.28E-01 ap=  .036 w=    13. nu=  2.86 lam=   7.98
+ Ookg1mOokG2=.506E-02 Aokg1=.32E-05 alkg1palskg2=.506E-02 be=  .193 als=  4.52 RGI=2000
+ CCG1=0.0P CCG2=0.0P  CPG1 = 0.0p CG1G2 = 0.0p CCP=0.0P  ;                                    
.ENDS                                                                           
****************************************************                            
.SUBCKT EL41_triode 1 2 3; A G C;                                               
* ExtractModel V1.010
* Model created: 22-Dec-13                                                      
X1 1 2 3 TriodeK MU= 25.06 EX=1.345 KG1= 172.1 KP= 133.6 KVB= 1952. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;                                                
.ENDS                                                                           
****************************************************                            
****************************************************                            
.SUBCKT EL84 1 2 3 4 ; A G2 G1 C;                                           
* ExtractModel V1.010
* Model created: 15-Dec-13                                                      
X1 1 2 3 4 BTetrodeD  MU= 23.36 EX=1.138 kG1= 117.4 KP= 152.4 kVB = 4015.8 kG2= 1275.0
+Sc=.38E-01 ap=  .054 w=    58. nu=  1.56 lam=   4.13
+ Ookg1mOokG2=.773E-02 Aokg1=.37E-05 alkg1palskg2=.773E-02 be=  .148 als=  7.66 RGI=2000
+ CCG1=10.8P CCG2=0.0P  CPG1 = 0.5p CG1G2 = 0.0p CCP=6.5P  ;                                    
.ENDS                                                                           
****************************************************                            
.SUBCKT EL84_triode 1 2 3; A G C;                                               
* ExtractModel V1.010
* Model created: 15-Dec-13                                                      
X1 1 2 3 TriodeK MU= 23.36 EX=1.202 KG1= 117.4 KP= 152.4 KVB= 4016. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;                                                
.ENDS                                                                           
****************************************************                            
****************************************************                            
.SUBCKT EL86 1 2 3 4 ; A G2 G1 C;                                           
* ExtractModel V1.010
* Model created: 22-Dec-13                                                      
X1 1 2 3 4 BTetrodeD  MU=  7.99 EX=1.723 kG1= 906.0 KP=  71.9 kVB = 6950.2 kG2=31112.7
+Sc=.20E+00 ap=  .028 w=    12. nu=  2.19 lam=  26.47
+ Ookg1mOokG2=.107E-02 Aokg1=.40E-06 alkg1palskg2=.107E-02 be=  .291 als= 27.20 RGI=2000
+ CCG1=0.0P CCG2=0.0P  CPG1 = 0.0p CG1G2 = 0.0p CCP=0.0P  ;                                    
.ENDS                                                                           
****************************************************                            
.SUBCKT EL86_triode 1 2 3; A G C;                                               
* ExtractModel V1.010
* Model created: 22-Dec-13                                                      
X1 1 2 3 TriodeK MU=  7.99 EX=1.763 KG1= 906.0 KP=  71.9 KVB= 6950. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;                                                
.ENDS                                                                           
****************************************************       
****************************************************         
.SUBCKT EL500 1 2 3 4 ; A G2 G1 C;                                          
* ExtractModel V1.000
* Model created: 13-Dec-13                                                      
X1 1 2 3 4 BTetrodeD  MU=  5.64 EX=1.588 kG1= 532.4 KP=  47.5 kVB = 6642.7 kG2=10888.1
+Sc=.79E-02 ap=  .045 w=    -8. nu=  1.20 lam=   1.62
+ Ookg1mOokG2=.179E-02 Aokg1=.11E-05 alkg1palskg2=.179E-02 be=  .054 als= 16.55 RGI=2000
+ CCG1=0.0P CCG2=0.0P  CPG1 = 1.75p CG1G2 = 0.0p CCP=0.0P  ;                                    
.ENDS                                                                           
****************************************************                            
.SUBCKT EL500_triode 1 2 3; A G C;                                              
* ExtractModel V1.000
* Model created: 13-Dec-13                                                      
X1 1 2 3 TriodeK MU=  5.64 EX=1.645 KG1= 532.4 KP=  47.5 KVB= 6643. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;                                                
.ENDS                                                                           
****************************************************                            
****************************************************                            
.SUBCKT EL805 1 2 3 4 ; A G2 G1 C;                                          
* ExtractModel V1.000
* Model created: 12-Dec-13                                                      
X1 1 2 3 4 BTetrodeD  MU=  8.02 EX=1.395 kG1= 375.0 KP=  54.5 kVB = 3000.8 kG2= 7598.3
+Sc=.13E+00 ap=  .019 w=    23. nu=  3.87 lam=2161.60
+ Ookg1mOokG2=.254E-02 Aokg1=.11E-05 alkg1palskg2=.254E-02 be=  .250 als= 15.82 RGI=2000
+ CCG1=0.0P CCG2=0.0P  CPG1 = 0.0p CG1G2 = 0.0p CCP=0.0P  ;                                    
.ENDS                                                                           
****************************************************                            
.SUBCKT EL805_triode 1 2 3; A G C;                                              
* ExtractModel V1.000
* Model created: 12-Dec-13                                                      
X1 1 2 3 TriodeK MU=  8.02 EX=1.438 KG1= 375.0 KP=  54.5 KVB= 3001. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;                                                
.ENDS                                                                           
****************************************************                            
****************************************************                            
.SUBCKT EZ80 1 2 3; A1 A2 C;                                                          
* ExtractModel V .92
* Model created: 08-Nov-13                                                      
X1 1 3 DiodeK  EX=1.410 k = 975.4 eps=   -.1
+ CCP=0.0P  ;                                                                   
X2 2 3 DiodeK  EX=1.410 k = 975.4 eps=   -.1
+ CCP=0.0P  ;                                                                   
.ENDS                                                                           
****************************************************                            
****************************************************                            
.SUBCKT GZ37 1 2 3; A1 A2 C;                                                          
*
X1 1 2 3 CV378
.ENDS                                                                           
****************************************************                            
****************************************************
.SUBCKT PABC80_C 1 2 3; A G C;
*      Extract V1.037
* Model created:  9-Feb-2014
X1 1 2 3 TriodeK MU= 67.95 EX=1.324 KG1= 885.7 KP= 469.6 KVB= 2671. RGI=2000
+ CCG=2.0P  CGP=1.2P CCP=2.1P  ;
.ENDS
****************************************************
.SUBCKT PABC80_D1 1 2; A C;
*      Extract V1.037
* Model created:  9-Feb-2014
X1 1 2 DiodeK  EX=1.106 k = 3364.8 eps=   -.4
+ CCP=0.9P  ;
.ENDS
****************************************************
.SUBCKT PABC80_D2 1 2; A C;
* Equivalent to D3
*      Extract V1.037
* Model created:  9-Feb-2014
X1 1 2 DiodeK  EX=1.152 k =  198.4 eps=    .0
+ CCP=4.5P  ;
.ENDS
****************************************************                            
****************************************************                            
.SUBCKT PC86 1 2 3; A G C;                                                      
* ExtractModel V .998
* Model created: 07-Dec-13                                                      
X1 1 2 3 TriodeK MU= 76.35 EX=1.286 KG1=  79.4 KP= 594.3 KVB= 1524. RGI=2000
+ CCG=3.6P  CGP=2.0P CCP=0.2P  ;                                                
.ENDS                                                                           
****************************************************                            
****************************************************                            
.SUBCKT PCC88 1 2 3; A G C;
X1 1 2 3 ECC88
.ENDS                                                    
****************************************************                            
****************************************************                            
.SUBCKT PCF80_F 1 2 3 4 ; A G2 G1 C;                                         
* ExtractModel V .996
* Model created: 02-Dec-13                                                      
X1 1 2 3 4 PenthodeD  MU= 51.1 EX=1.097 kG1= 168.0 KP= 249.5 kVB =  6926.7 kG2=  940.2
+ Ookg1mOokG2=.49E-02 Aokg1=.42E-13 alkg1palskg2=.49E-02 be=   .28 als=  4.77 RGI=2000
+ CCG1=5.5P CCG2=0.0P  CPG1 = 0.025p CG1G2 = 0.0p CCP=3.8P  ;                                    
.ENDS                                                                           
****************************************************                            
.SUBCKT PCF80_F_triode 1 2 3; A G C;                                             
* ExtractModel V .996
* Model created: 02-Dec-13                                                      
X1 1 2 3 TriodeK MU= 51.1 EX=1.097 KG1= 168.0 KP= 249.5 KVB= 6927. RGI=2000
+ CCG=5.5P  CGP=0.0P CCP=3.8P  ;                                                
.ENDS                                                                           
****************************************************                            
.SUBCKT PCF80_C 1 2 3; A G C;                                                    
* ExtractModel V .996
* Model created: 01-Dec-13                                                      
X1 1 2 3 TriodeK MU= 20.7 EX=1.277 KG1= 320.3 KP=  74.7 KVB=  944. RGI=2000
+ CCG=2.5P  CGP=1.5P CCP=1.8P  ;                                                
.ENDS                                                                           
****************************************************
****************************************************
.SUBCKT PF86 1 2 3 4; A G2 G1 C;                                                    
X1 1 2 3 4 EF86
.ENDS                           
****************************************************                            
****************************************************
.SUBCKT PCL81L 1 2 3 4 ; A G2 G1 C;
*      Extract V1.999
* Model created:  8-Nov-2015
*
X1 1 2 3 4 BTetrodeDE  MU= 21.22 EX=1.333 kG1= 167.2 KP=  99.5 kVB = 5055.5 kG2= 1185.2
+Sc=.94E-01 ap= 0.012 w=    57. nu=  8.06 lam=  1007.7
+ Ookg1mOokG2=.514E-02 Aokg1=.37E-05 alkg1palskg2=.514E-02 be= 0.123 als=  4.78 RGI=2000
+ CCG1=0.0P  CCG2 = 0.0p CPG1 = 0.0p  CG1G2 = 0.0p CCP=0.0P  ;
.ENDS
****************************************************
.SUBCKT PCL81C 1 2 3; A G C;
*      Extract V1.999
* Model created:  8-Nov-2015
*
X1 1 2 3 TriodeK MU= 63.02 EX=1.225 KG1= 707.8 KP= 373.7 KVB= 6496. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;
.ENDS
****************************************************                            
****************************************************                            
.SUBCKT PCL84_C 1 2 3; A G C;                                                    
* ExtractModel V1.010
* Model created: 22-Dec-13                                                      
X1 1 2 3 TriodeK MU= 87.21 EX=1.362 KG1= 213.9 KP= 345.3 KVB= 2351. RGI=2000
+ CCG=4.0P  CGP=2.7P CCP=2.3P  ;                                                
.ENDS                                                                           
****************************************************                            
.SUBCKT PCL84_L 1 2 3 4 ; A G2 G1 C;                                         
* ExtractModel V1.010

* Model created: 22-Dec-13                                                      
X1 1 2 3 4 BTetrodeD  MU= 43.18 EX=1.338 kG1= 129.2 KP= 208.6 kVB = 2779.8 kG2=  838.9
+Sc=.83E+01 ap=  .057 w=    36. nu= -1.99 lam=  20.83
+ Ookg1mOokG2=.655E-02 Aokg1=.26E-05 alkg1palskg2=.655E-02 be=  .196 als=  4.78 RGI=2000
+ CCG1=9.0P CCG2=0.0P  CPG1 = 0.1p CG1G2 = 0.0p CCP=4.5P  ;                                    
.ENDS                                                                           
****************************************************                            
.SUBCKT PCL84_L_triode 1 2 3; A G C;                                             
* ExtractModel V1.010
* Model created: 22-Dec-13                                                      
X1 1 2 3 TriodeK MU= 43.18 EX=1.401 KG1= 129.2 KP= 208.6 KVB= 2780. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;                                                
.ENDS                                                                           
****************************************************                            
****************************************************                            
.SUBCKT PCL85_C 1 2 3; A G C;                                                    
*      Extract V1.992
* Model created: 21-Sep-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU= 59.69 EX=1.119 KG1= 204.6 KP= 289.0 KVB= 3326. RGI=2000
+ CCG=4.0P  CGP=2.7P CCP=2.3P  ;                                                
.ENDS                                                                           
****************************************************                            
.SUBCKT PCL85_L 1 2 3 4 ; A G2 G1 C;                                         
*      Extract V1.992
* Model created: 21-Sep-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 4 BTetrodeDE  MU=  9.19 EX=1.310 kG1= 229.6 KP=  47.8 kVB = 1242.3 kG2= 2417.7
+Sc=.39E-01 ap=  .020 w=    13. nu=  3.44 lam=    22.5
+ Ookg1mOokG2=.394E-02 Aokg1=.32E-05 alkg1palskg2=.394E-02 be=  .134 als=  5.68 RGI=2000
+ CCG1=9.0P CCG2=0.0P  CPG1 = 0.6p CG1G2 = 0.0p CCP=4.5P  ;                                    
.ENDS                                                                           
****************************************************                            
.SUBCKT PCL85_L_triode 1 2 3; A G C;                                             
*      Extract V1.992
* Model created: 21-Sep-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU=  9.19 EX=1.388 KG1= 229.6 KP=  47.8 KVB= 1242. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;                                                
.ENDS                                                                           
****************************************************                            
****************************************************                            
.SUBCKT PCL86_C 1 2 3; A G C;                                                    
*      Extract V1.992
* Model created: 21-Sep-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU=129.18 EX= .900 KG1= 405.6 KP= 680.6 KVB= 4780. RGI=2000
+ CCG=2.3P  CGP=1.4P CCP=2.5P  ;                                                
.ENDS                                                                           
****************************************************                            
.SUBCKT PCL86_L 1 2 3 4 ; A G2 G1 C;
*      Extract V1.992
* Model created: 21-Sep-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 4 BTetrodeDE  MU= 22.90 EX=1.271 kG1= 155.0 KP= 150.7 kVB = 3788.2 kG2=  905.2
+Sc=.30E-01 ap=  .020 w=    33. nu=  7.05 lam=   847.9
+ Ookg1mOokG2=.535E-02 Aokg1=.35E-05 alkg1palskg2=.535E-02 be=  .093 als=  2.75 RGI=2000
+ CCG1=10.0P CCG2=0.0P  CPG1 = 0.4p CG1G2 = 0.0p CCP=0.0P  ;                                    
.ENDS                                                                           
****************************************************                            
.SUBCKT PCL86_L_triode 1 2 3; A G C;                                             
*      Extract V1.992
* Model created: 21-Sep-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU= 22.90 EX=1.349 KG1= 155.0 KP= 150.7 KVB= 3788. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;                                                
.ENDS                                                                           
****************************************************                            
****************************************************
.SUBCKT PL36 1 2 3 4 ; A G2 G1 C;
*      Extract V1.993
* Model created: 10-Nov-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 4 BTetrodeD  MU=  6.05 EX=1.298 kG1= 180.5 KP=  32.5 kVB = 2968.7 kG2=19322.3
+Sc=.26E+00 ap=  .011 w=    50. nu=  2.60 lam=     4.3
+ Ookg1mOokG2=.549E-02 Aokg1=.32E-05 alkg1palskg2=.549E-02 be=  .142 als= 99.66 RGI=2000
+ CCG1=15.5P  CCG2 = 0.0p CPG1 = 1.1p  CG1G2 = 0.0p CCP=8.0P  ;
.ENDS
**************************************************** 
.SUBCKT PL36_triode 1 2 3; A G C;
*      Extract V1.993
* Model created: 10-Nov-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU=  6.05 EX=1.355 KG1= 180.5 KP=  32.5 KVB= 2969. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT PL81 1 2 3 4 ; A G2 G1 C;
*      Extract V1.993
* Model created:  2-Dec-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 4 BTetrodeDE  MU=  5.86 EX=1.221 kG1= 234.6 KP=  45.7 kVB = 2143.1 kG2= 7700.8
+Sc=.21E+00 ap=  .012 w=    31. nu=  2.64 lam=  6179.9
+ Ookg1mOokG2=.413E-02 Aokg1=.53E-05 alkg1palskg2=.413E-02 be=  .081 als= 28.51 RGI=2000
+ CCG1=0.0P  CCG2 = 0.0p CPG1 = 0.0p  CG1G2 = 0.0p CCP=0.0P  ;
.ENDS
****************************************************                           
****************************************************
.SUBCKT PL81_triode 1 2 3; A G C;
*      Extract V1.993
* Model created:  2-Dec-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU=  5.86 EX=1.329 KG1= 234.6 KP=  45.7 KVB= 2143. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;
.ENDS
****************************************************                           
****************************************************
.SUBCKT PL82 1 2 3 4 ; A G2 G1 C;                                           
* ExtractModel V1.010
* Model created: 22-Dec-13                                                      
X1 1 2 3 4 BTetrodeD  MU= 11.24 EX=1.262 kG1= 163.5 KP=  77.3 kVB = 3419.7 kG2=  908.1
+Sc=.13E-01 ap=  .020 w=    79. nu=  3.51 lam=   4.38
+ Ookg1mOokG2=.501E-02 Aokg1=.31E-05 alkg1palskg2=.501E-02 be=  .113 als=  3.68 RGI=2000
+ CCG1=0.0P CCG2=0.0P  CPG1 = 0.0p CG1G2 = 0.0p CCP=0.0P  ;                                    
.ENDS                                                                           
****************************************************                            
.SUBCKT PL82_triode 1 2 3; A G C;                                               
* ExtractModel V1.010
* Model created: 22-Dec-13                                                      
X1 1 2 3 TriodeK MU= 11.24 EX=1.319 KG1= 163.5 KP=  77.3 KVB= 3420. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;                                                
.ENDS                                                                           
****************************************************
****************************************************
.SUBCKT PL83 1 2 3 4 ; A G2 G1 C;
*      Extract V1.993
* Model created:  2-Dec-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 4 BTetrodeD  MU= 26.58 EX=1.390 kG1= 188.6 KP= 174.5 kVB =  511.1 kG2= 1888.0
+Sc=.25E+00 ap=  .100 w=     5. nu=   .00 lam=    28.4
+ Ookg1mOokG2=.477E-02 Aokg1=.30E-06 alkg1palskg2=.477E-02 be=  .146 als=  5.25 RGI=2000
+ CCG1=0.0P  CCG2 = 0.0p CPG1 = 0.0p  CG1G2 = 0.0p CCP=0.0P  ;
.ENDS
****************************************************                            
.SUBCKT PL83_triode 1 2 3; A G C;
*      Extract V1.993
* Model created:  2-Dec-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU= 26.58 EX=1.399 KG1= 188.6 KP= 174.5 KVB=  511. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;
.ENDS
****************************************************                            
****************************************************                            
.SUBCKT PL84 1 2 3 4 ; A G2 G1 C;                                           
* ExtractModel V1.010
* Model created: 22-Dec-13                                                      
X1 1 2 3 4 BTetrodeD  MU=  8.37 EX=1.191 kG1= 223.7 KP=  73.1 kVB = 1365.2 kG2= 4961.0
+Sc=.45E-01 ap=  .025 w=    16. nu=  2.19 lam=   5.01
+ Ookg1mOokG2=.427E-02 Aokg1=.13E-05 alkg1palskg2=.427E-02 be=  .228 als= 17.60 RGI=2000
+ CCG1=0.0P CCG2=0.0P  CPG1 = 0.0p CG1G2 = 0.0p CCP=0.0P  ;                                    
.ENDS                                                                           
****************************************************                            
.SUBCKT PL84_triode 1 2 3; A G C;                                               
* ExtractModel V1.010
* Model created: 22-Dec-13                                                      
X1 1 2 3 TriodeK MU=  8.37 EX=1.224 KG1= 223.7 KP=  73.1 KVB= 1365. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;                                                
.ENDS                                                                           
****************************************************   
****************************************************                            
.SUBCKT PL95 1 2 3 4 ; A G2 G1 C;                                           
* ExtractModel V1.000
* Model created: 12-Dec-13                                                      
X1 1 2 3 4 BTetrodeD  MU= 19.82 EX= .692 kG1= 166.2 KP= 184.2 kVB =     .0 kG2=  964.3

+Sc=.16E-01 ap=  .019 w=     9. nu=  4.78 lam=   5.76
+ Ookg1mOokG2=.498E-02 Aokg1=.19E-05 alkg1palskg2=.498E-02 be=  .207 als=  3.63 RGI=2000
+ CCG1=0.0P CCG2=0.0P  CPG1 = 0.0p CG1G2 = 0.0p CCP=0.0P  ;                                    
.ENDS                                                                           
****************************************************                            
.SUBCKT PL95_triode 1 2 3; A G C;                                               
* ExtractModel V1.000
* Model created: 12-Dec-13                                                      
X1 1 2 3 TriodeK MU= 19.82 EX= .737 KG1= 166.2 KP= 184.2 KVB=    0. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;                                                
.ENDS                                                                           
****************************************************                            
****************************************************                            
.SUBCKT PL504 1 2 3 4
X1 1 2 3 4 EL500
.ENDS
****************************************************                            
.SUBCKT PL504_triode 1 2 3
X1 1 2 3 EL500_triode
.ENDS
****************************************************                            
****************************************************                            
.SUBCKT PL509 1 2 3 4 ; A G2 G1 C;                                          
* ExtractModel V .997
* Model created: 07-Dec-13                                                      
X1 1 2 3 4 BTetrodeDE  MU=  3.64 EX=1.845 kG1=1401.1 KP=  21.1 kVB =10046.9 kG2=32547.8
+Sc=.63E-02 ap=  .041 w=    -2. nu=   .32 lam=   1.38
+ Ookg1mOokG2=.683E-03 Aokg1=.70E-06 alkg1palskg2=.683E-03 be=  .057 als= 17.58 RGI=2000
+ CCG1=0.0P CCG2=0.0P  CPG1 = 3.0p CG1G2 = 0.0p CCP=0.0P  ;                                    
.ENDS                                                                           
****************************************************                            
.SUBCKT PL509_triode 1 2 3; A G C;                                              
* ExtractModel V .997
* Model created: 07-Dec-13                                                      
X1 1 2 3 TriodeK MU=  3.6 EX=1.926 KG1=1401.1 KP=  21.1 KVB=10047. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;                                                
.ENDS                                                                           
****************************************************                            
****************************************************
.SUBCKT PY82 1 2; A C;
*      Extract V1.992
* Model created:  8-Sep-2014
X1 1 2 DiodeK  EX=1.295 k =  154.3 eps=    .1
+ CCP=0.0P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT RS1019 1 2 3 4 ; A G2 G1 C;
*      Extract V1.035 / OH2NLT 10.2.2014
* Model created: 11-Feb-2014
*
* Data traced by Juha Niinikoski [mailto:juha.niinikoski@sitecno.fi]
*
X1 1 2 3 4 BTetrodeDE  MU= 10.70 EX=1.352 kG1= 245.0 KP=  43.5 kVB = 2785.7 kG2= 2013.5
+Sc=.22E-01 ap=  .014 w=    19. nu=  3.09 lam=     6.3
+ Ookg1mOokG2=.359E-02 Aokg1=.22E-05 alkg1palskg2=.359E-02 be=  .116 als=  3.80 RGI=2000
+ CCG1=7.5P  CCG2 = 3.5p CPG1 = 0.04p  CG1G2 = 2.5p CCP=2.6P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT UY1N 1 2; A C;
*      Extract V1.998
* Model created: 24-Feb-2015
*
* Thanks to Anders Magnusson (ragge@ludd.ltu.se)
*
* Telefunken UY1N with readings close to specs.
X1 1 2 DiodeK  EX=1.249 k =  186.1 eps=   -.2
+ CCP=0.0P  ;
.ENDS
****************************************************                            
****************************************************                            
.SUBCKT UY11 1 2; A C;                                                      
X1 1 2 UY1N
.ENDS                                                                           
****************************************************                            
*
*
* American tubes follow below
*
****************************************************                            
****************************************************                            

****************************************************
****************************************************
.SUBCKT 27 1 2 3; A G C;
*      Extract V1.992
* Model created:  5-Sep-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU=  9.69 EX=1.299 KG1=2115.5 KP=  71.0 KVB=  533. RGI=2000
+ CCG=3.1P  CGP=3.3P CCP=2.3P  ;
.ENDS
 ****************************************************
****************************************************
.SUBCKT 47 1 2 3 4 ; A G2 G1 C;
*      Extract V1.991
* Model created: 31-Aug-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
*
* Traced by Ale Moglia (valves@bartola.co.uk) using uTracer
*
X1 1 2 3 4 BTetrodeD  MU=  7.91 EX=1.358 kG1=1253.3 KP=  47.5 kVB =     .0 kG2= 7721.3
+Sc=.50E-01 ap=  .079 w=     8. nu=   .22 lam=     6.1
+ Ookg1mOokG2=.668E-03 Aokg1=.43E-06 alkg1palskg2=.668E-03 be=  .086 als=  3.48 RGI=2000
+ CCG1=8.6P  CCG2 = 0.0p CPG1 = 1.2p  CG1G2 = 0.0p CCP=13.0P  ;
.ENDS
****************************************************
.SUBCKT 47_triode 1 2 3; A G C;
*      Extract V1.991
* Model created: 31-Aug-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
*
* Traced by Ale Moglia (valves@bartola.co.uk) using uTracer
*
X1 1 2 3 TriodeK MU=  7.91 EX=1.415 KG1=1253.3 KP=  47.5 KVB=    0. RGI=2000
+ CCG=8.6P  CGP=0.0P CCP=13.0P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT 807 1 2 3 4 ; A G2 G1 C;
*      Extract V1.998
* Model created: 13-Feb-2015
*
X1 1 2 3 4 BTetrodeD  MU=  9.70 EX=1.347 kG1= 480.7 KP=  42.4 kVB = 1308.7 kG2= 7551.7
+Sc=.42E-01 ap=  .017 w=    11. nu=  3.30 lam=     9.4
+ Ookg1mOokG2=.195E-02 Aokg1=.10E-05 alkg1palskg2=.195E-02 be=  .236 als= 11.71 RGI=2000
+ CCG1=12.0P  CCG2 = 0.0p CPG1 = 0.2p  CG1G2 = 0.0p CCP=7.0P  ;
.ENDS
****************************************************
.SUBCKT 807_triode 1 2 3; A G C;
*      Extract V1.998
* Model created: 13-Feb-2015
*
X1 1 2 3 TriodeK MU=  9.70 EX=1.401 KG1= 480.7 KP=  42.4 KVB= 1309. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT 1624 1 2 3 4 ; A G2 G1 C;
*      Extract V1.990
* Model created: 30-Aug-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
*
* Traced by Ale Moglia (valves@bartola.co.uk) using uTracer
*
X1 1 2 3 4 BTetrodeDE  MU= 13.08 EX=1.250 kG1= 347.4 KP=  40.4 kVB =-4201.7 kG2= 3796.9
+Sc=.46E-01 ap= 0.016 w=    36. nu=  3.71 lam=     8.4
+ Ookg1mOokG2=.262E-02 Aokg1=.13E-05 alkg1palskg2=.262E-02 be= 0.080 als=  4.50 RGI=2000
+ CCG1=11.0P  CCG2 = 0.0p CPG1 = 0.25p  CG1G2 = 0.0p CCP=7.5P  ;
.ENDS
****************************************************
.SUBCKT 1624_triode 1 2 3; A G C;
*      Extract V1.990
* Model created: 30-Aug-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
*
* Traced by Ale Moglia (valves@bartola.co.uk) using uTracer
*
X1 1 2 3 TriodeK MU= 13.08 EX=1.306 KG1= 347.4 KP=  40.4 KVB=-4202. RGI=2000
+ CCG=11.0P  CGP=0.P CCP=7.5P  ;
.ENDS
 
****************************************************
****************************************************
.SUBCKT 5844 1 2 3; A G C;
*      Extract V1.036
* Model created:  8-Feb-2014
X1 1 2 3 TriodeK MU= 25.70 EX=1.626 KG1= 876.1 KP= 142.8 KVB= 8201. RGI=2000
+ CCG=2.4P  CGP=2.7P CCP=0.45P  ;
.ENDS
****************************************************                            
****************************************************
.SUBCKT 6080 1 2 3; A G C;
*      Extract V1.995
* Model created: 21-Feb-2015
*
* Thanks to Anders Magnusson (ragge@ludd.ltu.se)
*
* Capacitances from Philips Dec. 1968
* Measured values lower than nominal but inside allowed design spread.
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU=  3.25 EX=1.379 KG1= 271.3 KP=   7.4 KVB=   19. RGI=2000
+ CCG=5.5P  CGP=8.6P CCP=2.5P  ;
.ENDS
****************************************************                            
****************************************************
.SUBCKT 5U4 1 2 3; A C;
*      Extract V1.995
* Model created: 13-Dec-2014
X1 1 3 DiodeK  EX=1.395 k =  990.4 eps=   -.1
+ CCP=0.0P  ;
X2 2 3 DiodeK  EX=1.395 k =  990.4 eps=   -.1
+ CCP=0.0P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT 5V4 1 2 3; A1 A2 C;
*      Extract V1.995
* Model created:  7-Dec-2014
X1 1 3 DiodeK  EX=1.421 k =  705.5 eps=    .6
+ CCP=0.0P  ;
X2 2 3 DiodeK  EX=1.421 k =  705.5 eps=    .6
+ CCP=0.0P  ;
.ENDS
**************************************************** 
****************************************************
.SUBCKT 5Y3 1 2 3; A C;
*      Extract V1.995
* Model created: 13-Dec-2014
X1 1 3 DiodeK  EX=1.522 k = 2615.6 eps=    .2
+ CCP=0.0P  ;
X2 2 3 DiodeK  EX=1.522 k = 2615.6 eps=    .2
+ CCP=0.0P  ;
.ENDS 
****************************************************
****************************************************
.SUBCKT 6AL5 1 2; A C;
*      Extract V3.010
* Model created:  4-Oct-2016
* Large variation in tubes. Took a diode somewhere inbetween.
X1 1 2 DiodeK  EX=1.079 k =  336.4 eps=   0.2
+ CCP=3.0P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT 6AQ5 1 2 3 4 ; A G2 G1 C;
*      Extract V1.990
* Model created:  7-Jun-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 4 BTetrodeDE  MU= 10.41 EX=1.292 kG1= 642.1 KP=  59.6 kVB =  597.2 kG2= 8511.7
+Sc=.18E+00 ap=  .012 w=    78. nu=   .59 lam=     6.1
+ Ookg1mOokG2=.144E-02 Aokg1=.72E-06 alkg1palskg2=.144E-02 be=  .118 als=  9.11 RGI=2000
+ CCG1=8.0P  CCG2 = 0.0p CPG1 = 0.4p  CG1G2 = 0.0p CCP=9.0P  ;
.ENDS
****************************************************
.SUBCKT 6AQ5_triode 1 2 3; A G C;
*      Extract V1.990
* Model created:  7-Jun-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU= 10.41 EX=1.34 KG1= 642.1 KP=  59.6 KVB=  597. RGI=2000
+ CCG=8.0P  CGP=2.0P CCP=9.0P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT 6AS7 1 2 3; A G C;
*      Extract V1.980
* Model is based on a simultaneous fit of 8 different triodes
* Model created: 26-May-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU=  1.95 EX=1.860 KG1=7760.3 KP=  20.9 KVB= 3332. RGI=2000
+ CCG=6.8P  CGP=10.5P CCP=2.3P  ;
.ENDS
***************************************************
****************************************************
.SUBCKT 6AU4 1 2; A C;
*      Extract V1.999
* Model created:  5-Jul-2015
*
X1 1 2 DiodeK  EX=1.104 k =  116.0 eps=    .3
+ CCP=7.5P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT 6Ax4 1 2; A C;
*      Extract V1.999
* Model created:  5-Jul-2015
*
X1 1 2 DiodeK  EX=1.271 k =  312.1 eps=    .2
+ CCP=6.8P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT 6H13C 1 2 3; A G C;
* Aka 6AS7, russian version
*      Extract V1.990
* Model created:  2-Jul-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU=  2.00 EX=1.498 KG1=1112.1 KP=  13.2 KVB= 1268. RGI=2000

+ CCG=6.8P  CGP=10.5P CCP=2.3P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT 6BE6 1 2 3 4 5; A G3 G2G4 G1 C;
X1 1 2 3 4 5 EK90
.ENDS                                                                           
****************************************************                            
****************************************************
.SUBCKT 6BG6G 1 2 3 4 ; A G2 G1 C;
*      Extract V1.999
* Model created: 20-Apr-2015
*
X1 1 2 3 4 BTetrodeDE  MU= 10.12 EX=1.279 kG1= 370.5 KP=  40.6 kVB = 2107.5 kG2= 5789.8
+Sc=.17E-01 ap=  .017 w=     0. nu=  1.97 lam=     5.5
+ Ookg1mOokG2=.253E-02 Aokg1=.11E-05 alkg1palskg2=.253E-02 be=  .072 als=  8.23 RGI=2000
+ CCG1=11.0P  CCG2 = 0.0p CPG1 = 0.5p  CG1G2 = 0.0p CCP=6.5P  ;
.ENDS
****************************************************
.SUBCKT 6BG6G_triode 1 2 3; A G C;
*      Extract V1.999
* Model created: 20-Apr-2015
*
X1 1 2 3 TriodeK MU= 10.12 EX=1.326 KG1= 370.5 KP=  40.6 KVB= 2108. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT 6BK7 1 2 3; A G C;
*      Extract V1.999
* Model created: 14-Jun-2015
*
X1 1 2 3 TriodeK MU= 60.59 EX=1.085 KG1= 174.2 KP= 167.3 KVB= 1324. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT 6BL7 1 2 3; A G C;
*      Extract V1.998
* Model created: 22-Feb-2015
* 
* Used two tube halves in fitting
*
X1 1 2 3 TriodeK MU= 15.75 EX=1.275 KG1= 335.6 KP= 113.4 KVB= 1912. RGI=2000
+ CCG=4.4P  CGP=4.2P CCP=3.0P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT 6BY6 1 2 3 4 5; A G3 G2G4 G1 C;
*      Extract V1.995
* Model created: 21-Mar-2015
*
* Thanks to Anders Magnusson (ragge@ludd.ltu.se)
*
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 4 5 HepthodeD MU= 31.1 MU3=.3E+05 EX=1.349 kG1= 175.7 KP=44.7 kVB =501.2 kG2=  368.7
+ MUp= 56.3 EXX= .048 kG1p=   1.3 KPp=  388.4 kVBp =   208.2
+ Ookg1mOokG2=.30E-02 Aokg1=.34E-06 al= .21E-01 alkg1palskg2=.30E-02 be=.15 als=1.05 RGI=2000
+ CCG1=5.4P  CCG3 = 6.9p CPG1 = 0.08p CG1G3 = 0.15p CCP=7.6P  ;
.ENDS
********************************************************************************************************
.SUBCKT 6C9 1 2 3 4 ; A G2 G1 C;
*      Extract V1.912
* Model created:  6-Apr-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 4 BTetrodeD  MU= 30.81 EX=1.213 kG1= 102.6 KP= 112.2 kVB =     .0 kG2=  922.7
+Sc=.56E-01 ap=  .022 w=    30. nu=  8.82 lam=     2.1
+ Ookg1mOokG2=.866E-02 Aokg1=.16E-05 alkg1palskg2=.866E-02 be=  .229 als=  7.80 RGI=2000
+ CCG1=4.4P  CCG2 = 0.0p CPG1 = 0.055p  CG1G2 = 0.0p CCP=2.2P  ;
.ENDS
****************************************************
.SUBCKT 6C9_triode 1 2 3; A G C;
*      Extract V1.912
* Model created:  6-Apr-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU= 30.81 EX=1.241 KG1= 102.6 KP= 112.2 KVB=    0. RGI=2000
+ CCG=3.8P  CGP=3.0P CCP=0.44P  ;
.ENDS 
****************************************************                             
****************************************************
.SUBCKT 6CD6 1 2 3 4 ; A G2 G1 C;
*      Extract V1.998
* Model created: 28-Feb-2015
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 4 BTetrodeDE  MU=  4.43 EX=1.357 kG1= 341.1 KP=  17.2 kVB = 5650.5 kG2= 7303.4
+Sc=.20E+00 ap=  .011 w=    47. nu=  1.22 lam=  2056.8
+ Ookg1mOokG2=.279E-02 Aokg1=.34E-05 alkg1palskg2=.279E-02 be=  .181 als= 13.06 RGI=2000
+ CCG1=22.0P  CCG2 = 0.0p CPG1 = 1.1p  CG1G2 = 0.0p CCP=8.5P  ;
.ENDS
****************************************************
.SUBCKT 6CD6_triode 1 2 3; A G C;
*      Extract V1.998
* Model created: 28-Feb-2015
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU=  4.43 EX=1.454 KG1= 341.1 KP=  17.2 KVB= 5650. RGI=2000
+ CCG=22.0P  CGP=14.0P CCP=8.5P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT 6CG7 1 2 3; A G C;
*      Extract V1.999
* Model created: 21-Jun-2015
*
* parameters measured on recent (late 60-ies, early 70-ies) tubes that differ in the cut-off
* region from 6SN7 and are (even) more linear
*
X1 1 2 3 TriodeK MU= 21.26 EX=1.387 KG1= 764.4 KP= 133.8 KVB=  751. RGI=2000
+ CCG=2.3P  CGP=4.0P CCP=2.2P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT 6CJ3_1 1 2; A C;
*      Extract V1.999
* Model created:  5-Jul-2015
*
X1 1 2 DiodeK  EX=1.009 k =   51.2 eps=    .2
+ CCP=12.0P  ;
.ENDS
****************************************************
.SUBCKT 6CS6 1 2 3 4 5; A G3 G2G4 G1 C;
X1 1 2 3 4 5 EH90
.ENDS                                                                           
****************************************************                            
****************************************************
.SUBCKT 6DN7_1 1 2 3; A G C;
*      Extract V1.998
* Model created: 22-Feb-2015
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU= 22.13 EX=1.420 KG1= 818.2 KP= 164.4 KVB= 4518. RGI=2000
+ CCG=2.2P  CGP=4.0P CCP=0.7P  ;
.ENDS
****************************************************
.SUBCKT 6DN7_2 1 2 3; A G C;
*      Extract V1.998
* Model created: 22-Feb-2015
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU= 17.46 EX=1.378 KG1= 300.1 KP=  86.1 KVB=  712. RGI=2000
+ CCG=4.6P  CGP=5.5P CCP=1.0P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT 6F6 1 2 3 4 ; A G2 G1 C;
*      Extract V1.998
* Model created: 22-Feb-2015
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 4 PenthodeD  MU=  7.5 EX=1.375 kG1=1186.2 KP= 400 kVB =  3706.0 kG2= 8976.8
+ Ookg1mOokG2=.73E-03 Aokg1=.12E-06 alkg1palskg2=.73E-03 be=   .09 als=  3.56 RGI=2000
+ CCG1=6.5P  CCG2 = 0.0p CPG1 = 0.26p CG1G2 = 0.0p CCP=13.5P  ;
.ENDS
****************************************************
.SUBCKT 6F6_triode 1 2 3; A G C;
*      Extract V1.998
* Model created: 22-Feb-2015
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU=  7.51 EX=1.391 KG1=1186.2 KP= 400 KVB= 3706. RGI=2000
+ CCG=6.5P  CGP=6.5P CCP=13.5P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT 6GH8_F 1 2 3 4 ; A G2 G1 C;
*      Extract V1.980
* Model created: 18-May-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.

* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 4 PenthodeD  MU= 56.2 EX=1.236 kG1= 224.6 KP= 102.0 kVB =  2316.6 kG2= 1016.7
+ Ookg1mOokG2=.35E-02 Aokg1=.13E-07 alkg1palskg2=.35E-02 be=   .13 als=  3.91 RGI=2000
+ CCG1=0.0P  CCG2 = 0.0p CPG1 = 0.0p CG1G2 = 0.0p CCP=0.0P  ;
.ENDS
****************************************************
.SUBCKT 6GH8_F_triode 1 2 3; A G C;
*      Extract V1.980
* Model created: 18-May-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU= 56.18 EX=1.237 KG1= 224.6 KP= 102.0 KVB= 2317. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;
.ENDS
****************************************************
.SUBCKT 6GH8_C 1 2 3; A G C;
*      Extract V1.950
* Model created: 18-May-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU= 55.04 EX=1.074 KG1= 174.1 KP= 131.4 KVB= 2094. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT 6GU7 1 2 3; A G C;
*      Extract V1.950
* Model created: 26-Apr-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU= 24.12 EX=1.187 KG1= 338.6 KP=  82.9 KVB=  542. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;
.ENDS
****************************************************                             
****************************************************
.SUBCKT 6J6 1 2 3; A G C;
*      Extract V1.990
* Model created: 11-Jun-2014
* Average of the two tube halves
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU= 38.00 EX=1.262 KG1= 240.7 KP= 142.6 KVB= 1700. RGI=2000
+ CCG=2.6P  CGP=1.5P CCP=1.6P  ;
.ENDS
****************************************************                             
****************************************************
.SUBCKT 6JU8 1 2; A C;
*      Extract V1.998
* Model created: 22-Feb-2015
* 4 diodes in one package
*
X1 1 2 DiodeK  EX= .869 k =  200.8 eps=   -.1
+ CCP=2.2P  ;
.ENDS
****************************************************                             
****************************************************
.SUBCKT 6K6 1 2 3 4 ; A G2 G1 C;
*      Extract V1.999
* Model created: 20-Apr-2015
*
X1 1 2 3 4 PenthodeD  MU= 10.4 EX=1.333 kG1= 786.5 KP=  27.6 kVB =  4529.3 kG2= 5968.8
+ Ookg1mOokG2=.11E-02 Aokg1=.20E-06 alkg1palskg2=.11E-02 be=   .13 als=  3.81 RGI=2000
+ CCG1=5.5P  CCG2 = 0.0p CPG1 = 0.5p CG1G2 = 0.0p CCP=6.0P  ;
.ENDS
****************************************************
.SUBCKT 6K6_triode 1 2 3; A G C;
*      Extract V1.999
* Model created: 20-Apr-2015
*
X1 1 2 3 TriodeK MU= 10.36 EX=1.353 KG1= 786.5 KP=  27.6 KVB= 4529. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;
.ENDS
****************************************************                             
****************************************************
.SUBCKT 6K7 1 2 3 4 ; A G2 G1 C;
*      Extract V3.000
* Model created: 22-Jan-2016
*
X1 1 2 3 4 PenthodeVD  MU= 15.5 EX=1.573 kG1=1407.7 KP=  36.0 kVB =  1309.0 kG2= 8335.8
+ MUb=  3.4 EXb=1.223 svar= 0.083
+ Ookg1mOokG2=.59E-03 Aokg1=.11E-11 alkg1palskg2=.59E-03 be=  0.15 als=  4.07 RGI=2000
+ CCG1=7.0P  CCG2 = 0.0p CPG1 = 0.0005p CG1G2 = 0.0p CCP=12.0P  ;
.ENDS

****************************************************
****************************************************                             
.SUBCKT 6L6GC 1 2 3 4 ; A G2 G1 C;                                          
* ExtractModel V .998
* Model created: 07-Dec-13                                                      
X1 1 2 3 4 BTetrodeDE  MU=  9.41 EX=1.306 kG1= 446.6 KP=  45.2 kVB = 3205.1 kG2= 6672.5
+Sc=.31E-01 ap=  .017 w=    -5. nu=  3.08 lam=  14.66
+ Ookg1mOokG2=.209E-02 Aokg1=.11E-05 alkg1palskg2=.209E-02 be=  .069 als=  8.10 RGI=2000
+ CCG1=10.0P CCG2=0.0P  CPG1 = 0.6p CG1G2 = 0.0p CCP=6.5P  ;                                    
.ENDS                                                                           
****************************************************                            
.SUBCKT 6l6GC_triode 1 2 3; A G C;                                              
* ExtractModel V .998
* Model created: 07-Dec-13                                                      
X1 1 2 3 TriodeK MU=  9.41 EX=1.356 KG1= 446.6 KP=  45.2 KVB= 3205. RGI=2000
+ CCG=10.0P  CGP=0.6P CCP=6.5P  ;                                                
.ENDS                                                                           
****************************************************                            
****************************************************
.SUBCKT 6LY8_C 1 2 3; A G C;
*      Extract V1.950
* Model created: 26-Apr-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU=147.85 EX=1.559 KG1= 363.6 KP= 549.5 KVB= 1915. RGI=2000
+ CCG=2.6P  CGP=3.8P CCP=2.8P  ;
.ENDS
****************************************************
.SUBCKT 6LY8_L 1 2 3 4 ; A G2 G1 C;
*      Extract V1.950
* Model created: 26-Apr-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 4 BTetrodeD  MU= 37.51 EX=1.251 kG1=  63.8 KP= 279.3 kVB = 2379.2 kG2=  387.8
+Sc=.12E-01 ap=  .018 w=    17. nu= 19.98 lam=  4188.0
+ Ookg1mOokG2=.131E-01 Aokg1=.47E-05 alkg1palskg2=.131E-01 be=  .399 als=  3.92 RGI=2000
+ CCG1=13.0P  CCG2 = 0.0p CPG1 = 0.075p  CG1G2 = 0.0p CCP=4.4P  ;
.ENDS
****************************************************
.SUBCKT 6LY8_L_triode 1 2 3; A G C;
*      Extract V1.950
* Model created: 26-Apr-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU= 37.51 EX=1.305 KG1=  63.8 KP= 279.3 KVB= 2379. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT 6SL7 1 2 3; A G C;
*      Extract V1.992
* Model created: 13-Sep-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU= 76.12 EX=1.169 KG1= 587.3 KP= 527.8 KVB= 5197. RGI=2000
+ CCG=2.15P  CGP=3.4P CCP=0.9P  ;
.ENDS
****************************************************                            
****************************************************
.SUBCKT 6SL7WGT_SIEM 1 2 3; A G C;
*      Extract V1.032
* Model created: 25-Jan-2014
*
* Siemens
* Traced and modelled by Richard Zajkowski (richard@zajkowski.net) using uTracer
*
X1 1 2 3 TriodeK MU= 91.32 EX=1.236 KG1= 585.5 KP= 318.5 KVB= 2569. RGI=2000
+ CCG=5.6P  CGP=3.6P CCP=3.0P  ;
.ENDS
****************************************************
.SUBCKT 6SL7_TS 1 2 3; A G C;
*      Extract V1.032
* Model created: 25-Jan-2014
* 
* Tung-Sol
* Traced and modelled by Richard Zajkowski (richard@zajkowski.net) using uTracer
*
X1 1 2 3 TriodeK MU= 73.44 EX=1.177 KG1= 598.8 KP= 321.0 KVB= 1584. RGI=2000
+ CCG=2.4P  CGP=2.8P CCP=2.5P  ;
.ENDS
****************************************************                            
****************************************************                            
.SUBCKT 6SN7 1 2 3; A G C;                                                      
* ExtractModel V .998
* Model created: 07-Dec-13                                                      
X1 1 2 3 TriodeK MU= 25.48 EX=1.313 KG1= 602.5 KP= 102.2 KVB=  350. RGI=2000
+ CCG=2.2P  CGP=4.0P CCP=0.7P  ;                                                
.ENDS                                                                           
****************************************************                            
****************************************************
.SUBCKT 6SQ7_D1 1 2; A C;
*      Extract V1.034
* Model created: 21-Jan-2014
X1 1 2 DiodeK  EX=1.667 k =19466.9 eps=   2.0
+ CCP=0.0P  ;
.ENDS
****************************************************
.SUBCKT 6SQ7_D2 1 2; A C;
*      Extract V1.034
* Model created: 21-Jan-2014
X1 1 2 DiodeK  EX=1.608 k =26181.6 eps=   1.3
+ CCP=0.0P  ;
.ENDS
****************************************************
.SUBCKT 6SQ7_C 1 2 3; A G C;
*      Extract V1.033
* Model created: 21-Jan-2014
X1 1 2 3 TriodeK MU=100.68 EX=1.094 KG1= 651.2 KP= 604.4 KVB= 9686. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;
.ENDS
****************************************************                            
****************************************************
.SUBCKT 6V6GT 1 2 3 4 ; A G2 G1 C;
*      Extract V1.980
* Model created:  7-Jun-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 4 BTetrodeDE  MU= 10.56 EX=1.306 kG1= 609.8 KP=  47.9 kVB = 2171.5 kG2=17267.3
+Sc=.81E-01 ap=  .013 w=    18. nu=   .92 lam=     5.7
+ Ookg1mOokG2=.158E-02 Aokg1=.57E-06 alkg1palskg2=.158E-02 be=  .068 als= 18.72 RGI=2000
+ CCG1=9.0P  CCG2 = 0.0p CPG1 = 0.7p  CG1G2 = 0.0p CCP=7.5P  ;
.ENDS
****************************************************
.SUBCKT 6V6_triode 1 2 3; A G C;
*      Extract V1.980
* Model created:  7-Jun-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU= 10.56 EX=1.347 KG1= 609.8 KP=  47.9 KVB= 2172. RGI=2000
+ CCG=9.0P  CGP=5.0P CCP=7.5P  ;
.ENDS
****************************************************                            
****************************************************
.SUBCKT 6W6 1 2 3 4 ; A G2 G1 C;
*      Extract V1.990
* Model created: 15-Jun-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 4 BTetrodeDE  MU=  8.53 EX=1.212 kG1= 270.0 KP=  45.2 kVB = 2585.0 kG2= 3396.9
+Sc=.35E-01 ap=  .020 w=     4. nu=  2.76 lam=     7.6
+ Ookg1mOokG2=.341E-02 Aokg1=.26E-05 alkg1palskg2=.341E-02 be=  .134 als=  8.75 RGI=2000
+ CCG1=0.0P  CCG2 = 0.0p CPG1 = 0.0p  CG1G2 = 0.0p CCP=0.0P  ;
.ENDS
****************************************************
.SUBCKT 6W6_triode 1 2 3; A G C;
*      Extract V1.990
* Model created: 15-Jun-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU=  8.53 EX=1.285 KG1= 270.0 KP=  45.2 KVB= 2585. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;
.ENDS
****************************************************                            
****************************************************                            
.SUBCKT 6X4WA 1 2 3; A1 A2 C;                                                         
* ExtractModel V .92
* Model created: 08-Nov-13                                                      
X1 1 3 DiodeK  EX=1.678 k =2801.0 eps=   2.3
+ CCP=0.0P  ;                                                                   
X2 2 3 DiodeK  EX=1.678 k =2801.0 eps=   2.3
+ CCP=0.0P  ;                                                                   
.ENDS                                                                           
****************************************************                            
****************************************************
.SUBCKT 6X5 1 2 3; A1 A2 C;
*      Extract V3.010
* Model created: 23-Oct-2016
*
X1 1 3 DiodeK  EX=1.215 k =  506.9 eps=   0.5
+ CCP=0.0P  ;
X2 2 3 DiodeK  EX=1.215 k =  506.9 eps=   0.5
+ CCP=0.0P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT 12AT7 1 2 3; A G C;
X1 1 2 3 ECC81
.ENDS
****************************************************
****************************************************
.SUBCKT 12AU7 1 2 3; A G C;
X1 1 2 3 ECC82
.ENDS
****************************************************
****************************************************
.SUBCKT 12AV7 1 2 3; A G C
X1 6BK7 1 2 3
.ENDS
****************************************************
****************************************************
.SUBCKT 12AX7 1 2 3; A G C;
X1 1 2 3 ECC83
.ENDS
****************************************************
****************************************************
.SUBCKT 12AY7 1 2 3; A G C;
*      Extract V1.999
* Model created: 14-Jun-2015
*
X1 1 2 3 TriodeK MU= 47.59 EX=1.135 KG1= 565.6 KP= 244.2 KVB= 3024. RGI=2000
+ CCG=1.4P  CGP=1.4P CCP=0.5P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT 12AZ7 1 2 3; A G C;
*      Extract V1.999
* Model created: 27-Jun-2015
*
X1 1 2 3 TriodeK MU= 80.17 EX=1.219 KG1= 157.2 KP= 186.2 KVB= 2714. RGI=2000
+ CCG=3.2P  CGP=1.9P CCP=0.4P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT 12B4 1 2 3; A G C;
*      Extract V1.999
* Model created: 27-Jun-2015
*
X1 1 2 3 TriodeK MU=  6.59 EX=1.409 KG1= 315.3 KP=  41.2 KVB= 2330. RGI=2000
+ CCG=5.0P  CGP=4.8P CCP=1.5P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT 12BH7 1 2 3; A G C;
*      Extract V1.990
* Model created: 11-Jun-2014
* Average of 2 tube halves
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 TriodeK MU= 22.89 EX=1.333 KG1= 530.3 KP=  79.1 KVB=  899. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;
.ENDS
****************************************************                            
****************************************************                            
.SUBCKT 12E1 1 2 3 4 ; A G2 G1 C;                                           
* ExtractModel V .998
* Model created: 07-Dec-13                                                      
X1 1 2 3 4 BTetrodeDE  MU=  5.08 EX=1.161 kG1= 141.7 KP=  28.7 kVB =18893.3 kG2= 1707.8
+Sc=.35E-01 ap=  .015 w=    58. nu=  2.81 lam=2190.14
+ Ookg1mOokG2=.647E-02 Aokg1=.59E-05 alkg1palskg2=.647E-02 be=  .134 als=  7.05 RGI=2000
+ CCG1=23.0P CCG2=0.0P  CPG1 = 0.85p CG1G2 = 0.0p CCP=8.0P  ;                                    
.ENDS                                                                           
****************************************************                            
.SUBCKT 12E1_triode 1 2 3; A G C;                                               
* ExtractModel V .998
* Model created: 07-Dec-13                                                      
X1 1 2 3 TriodeK MU=  5.08 EX=1.161 KG1= 141.7 KP=  28.7 KVB=18893. RGI=2000
+ CCG=23.0P  CGP=0.0P CCP=8.0P  ;                                                
.ENDS                                                                           
****************************************************                            
****************************************************                            

****************************************************                            
*
*
* Russian tubes follow below
*
****************************************************                            
****************************************************

****************************************************
****************************************************
.SUBCKT 4P1L 1 2 3 4 ; A G2 G1 C;
*      Extract V1.991
* Model created: 31-Aug-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
*
* Traced by Ale Moglia (valves@bartola.co.uk) using uTracer
*
X1 1 2 3 4 BTetrodeD  MU=  9.91 EX=1.295 kG1= 300.4 KP=  71.1 kVB = 1414.3 kG2= 3317.6
+Sc=.69E+00 ap= 0.011 w=   293. nu= -6.53 lam=     1.3
+ Ookg1mOokG2=.303E-02 Aokg1=.87E-06 alkg1palskg2=.303E-02 be= 0.093 als=  6.47 RGI=2000
+ CCG1=0.0P  CCG2 = 0.0p CPG1 = 0.0p CG1G2 = 0.0p CCP=0.0P  ;
.ENDS
****************************************************
.SUBCKT 4P1L_triode 1 2 3; A G C;
*      Extract V1.991
* Model created: 31-Aug-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
*
* Traced by Ale Moglia (valves@bartola.co.uk) using uTracer
*
X1 1 2 3 TriodeK MU=  9.91 EX=1.326 KG1= 300.4 KP=  71.1 KVB= 1414. RGI=2000
+ CCG=0.0P  CGP=0.0P CCP=0.0P  ;
.ENDS

****************************************************
****************************************************
.SUBCKT 6E5P 1 2 3 4 ; A G2 G1 C;
*      Extract V1.991
* Model created: 31-Aug-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
*
* Traced by Ale Moglia (valves@bartola.co.uk) using uTracer
*
X1 1 2 3 4 BTetrodeDE  MU= 31.61 EX=1.909 kG1= 105.0 KP=1999.9 kVB =     .0 kG2=  669.2
+Sc=.12E-01 ap=  .017 w=     0. nu= 11.59 lam=     3.0
+ Ookg1mOokG2=.803E-02 Aokg1=.60E-05 alkg1palskg2=.803E-02 be=  .043 als=  4.87 RGI=2000
+ CCG1=15P  CCG2 = 0.0p CPG1 = 0.65p  CG1G2 = 0.0p CCP=2.55P  ;
.ENDS
****************************************************
.SUBCKT 6E5P_triode 1 2 3; A G C;
*      Extract V1.991
* Model created: 31-Aug-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
*
* Traced by Ale Moglia (valves@bartola.co.uk) using uTracer
*
X1 1 2 3 TriodeK MU= 31.61 EX=1.999 KG1= 105.0 KP=1999.9 KVB=    0. RGI=2000
+ CCG=15P  CGP=0.0P CCP=2.55P  ;
.ENDS

****************************************************
****************************************************
.SUBCKT 6N1P-EV 1 2 3; A G C;
*      Extract V1.037
* Model created: 12-Apr-2014
*
* Traced and modelled by Richard Zajkowski (richard@zajkowski.net) using uTracer
*
X1 1 2 3 TriodeK MU= 37.81 EX=1.663 KG1= 502.1 KP= 235.1 KVB=  467. RGI=2000
+ CCG=4.8P CGP=2.7P CCP=2.2P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT 6N6P 1 2 3; A G C;
*      Extract V1.999
* Model created: 10-Jul-2015
*
* Tubes provided by Ray Waters
*
X1 1 2 3 TriodeK MU= 19.13 EX=1.579 KG1= 371.0 KP= 101.8 KVB=  359. RGI=2000
+ CCG=4.4P  CGP=3.5P CCP=1.8P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT 6N7 1 2 3; A G C;
*      Extract V1.037
* Model created: 12-Apr-2014
*
* Traced and modelled by Richard Zajkowski (richard@zajkowski.net) using uTracer
*
X1 1 2 3 TriodeK MU= 37.27 EX=1.275 KG1= 792.8 KP= 253.1 KVB= 2320. RGI=2000
+ CCG=4.5P  CGP=2.8P CCP=3.9P  ;
.ENDS
****************************************************
****************************************************
.SUBCKT 6P21S 1 2 3 4 ; A G2 G1 C;
*      Extract V1.990
* Model created: 31-Aug-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
*
* Traced by Ale Moglia (valves@bartola.co.uk) using uTracer
*
X1 1 2 3 4 BTetrodeDE  MU=  8.96 EX=1.624 kG1=1531.3 KP=  38.6 kVB =     .2 kG2=15839.1
+Sc=.43E-01 ap=  .019 w=     0. nu=  3.06 lam=    11.3
+ Ookg1mOokG2=.590E-03 Aokg1=.43E-06 alkg1palskg2=.590E-03 be=  .061 als=  5.23 RGI=2000
+ CCG1=8.2P  CCG2 = 0.0p CPG1 = 0.15p  CG1G2 = 0.0p CCP=6.5P  ;
.ENDS
****************************************************
.SUBCKT 6P21S_triode 1 2 3; A G C;
*      Extract V1.990
* Model created: 31-Aug-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
*
* Traced by Ale Moglia (valves@bartola.co.uk) using uTracer
*
X1 1 2 3 TriodeK MU=  8.96 EX=1.694 KG1=1531.3 KP=  38.6 KVB=    0. RGI=2000
+ CCG=8.2P  CGP=0.0P CCP=6.5P
.ENDS




****************************************************                            
****************************************************
*
* Below al generic models follow
*
*
****************************************************
.SUBCKT Penthodeg3DE 1 2 3 4 5; A G3 G2 G1 C
RE1  7 0  1MEG    ; DUMMY SO NODE 7 HAS 2 CONNECTIONS
E1 7 0 VALUE=
+{V(3,5)/KP*LOG(1+EXP(KP*(1/MU+(V(2,5)/Mu3+V(4,5))/SQRT(KVB+V(3,5)*V(3,5)))))}
E2   8 0 VALUE = {Ookg1mOokG2 + Aokg1*V(1,5) - alkg1palskg2*Exp(-be*V(1,5)*SQRT(be*V(1,5)))}
E3   9 0  VALUE = {0.5*(PWR(V(7),EX)+PWRS(V(7),EX))}
E4 10 0 VALUE= {V0 + V(2,5) + V(1,5)/mup}
E5   11 0  VALUE ={0.5*(PWR(V(10),EXX)+PWRS(V(10),EXX))/kg1p}
G1   1 5 VALUE = {V(8)*V(9)*(1-Exp(-V(11)))}
G2   3 5 VALUE = {V(9)/kg1 *(1+Aokg1*kg1*V(1,5)- al*Exp(-be*V(1,5)*SQRT(be*V(1,5)))) - V(8)*V(9)*(1-Exp(-V(11)))}
RCP  1 5  1G      ; FOR CONVERGENCE	A  - C
C1   4 5  {CCG1}   ; CATHODE-GRID 1	C  - G1
C4   2 5  {CCG3}   ; CATHODE-GRID 3	C  - G3
C5   2 4  {CG1G3}   ; GRID 1 -GRID 3	G1  - G3
C2   1 4  {CPG1}  ; GRID 1-PLATE	G1 - A
C3   1 5  {CCP}   ; CATHODE-PLATE	A  - C
R1   4 15 {RGI}   ; FOR GRID CURRENT	G1 - 5
D3  15 5  DX      ; FOR GRID CURRENT	5  - C
.MODEL DX D(IS=1N RS=1 CJO=10PF TT=1N)
.ENDS Penthodeg3DE

****************************************************
****************************************************
.SUBCKT HepthodeD 1 2 3 4 5; A G3 G2G4 G1 C
RE1  7 0  1MEG    ; DUMMY SO NODE 7 HAS 2 CONNECTIONS
E1 7 0 VALUE=
+{V(3,5)/KP*LOG(1+EXP(KP*(1/MU+(V(2,5)/Mu3+V(4,5))/SQRT(KVB+V(3,5)*V(3,5)))))}
E2   8 0 VALUE = {Ookg1mOokG2 + Aokg1*V(1,5) - alkg1palskg2/(1 + be*V(1,5))}
E3   9 0  VALUE = {0.5*(PWR(V(7),EX)+PWRS(V(7),EX))}
E4 10 0 VALUE=
+{V(3,5)/KPp*LOG(1+EXP(KPp*(1/MUp+V(2,5)/SQRT(KVBp+V(3,5)*V(3,5)))))}
E5   11 0  VALUE ={0.5*(PWR(V(10),EXX)+PWRS(V(10),EXX))/kg1p}
G1   1 5 VALUE = {V(8)*V(9)*V(11)}
G2   3 5 VALUE = {V(9)/kg1 *(1+Aokg1*kg1*V(1,5)- al/(1+be*V(1,5))) - V(8)*V(9)*V(11)}
RCP  1 5  1G      ; FOR CONVERGENCE	A  - C
C1   4 5  {CCG1}   ; CATHODE-GRID 1	C  - G1
C4   2 5  {CCG3}   ; CATHODE-GRID 3	C  - G3
C5   2 4  {CG1G3}   ; GRID 1 -GRID 3	G1  - G3
C2   1 4  {CPG1}  ; GRID 1-PLATE	G1 - A
C3   1 5  {CCP}   ; CATHODE-PLATE	A  - C
R1   4 15 {RGI}   ; FOR GRID CURRENT	G1 - 5
D3  15 5  DX      ; FOR GRID CURRENT	5  - C
.MODEL DX D(IS=1N RS=1 CJO=10PF TT=1N)
.ENDS HepthodeD

****************************************************                            
****************************************************                            
.SUBCKT BTetrodeD 1 2 3 4; A G2 G1 C                                            
RE1  7 0  1MEG    ; DUMMY SO NODE 7 HAS 2 CONNECTIONS                           
E1 7 0 VALUE=                                                                   
+{V(2,4)/KP*LOG(1+EXP(KP*(1/MU+V(3,4)/SQRT(KVB+V(2,4)*V(2,4)))))}               
E2   8 0 VALUE = {Ookg1mOokG2 + Aokg1*V(1,4) - alkg1palskg2/(1 + be*V(1,4))}    
E3   9 0 VALUE = {Sc/kG2*V(1,4)*(1+tanh(-ap*(V(1,4)-V(2,4)/lam+w+nu*V(3,4))))}  
G1   1 4 VALUE = {0.5*(PWR(V(7),EX)+PWRS(V(7),EX))*(V(8)-V(9))}
G2   2 4 VALUE = {0.5*(PWR(V(7),EX)+PWRS(V(7),EX))/KG2 * (1+ als/(1+be*V(1,4)))}
RCP  1 4  1G      ; FOR CONVERGENCE	A  - C                                      
C1   3 4  {CCG1}   ; CATHODE-GRID 1	C  - G1
C4   2 4  {CCG2}   ; CATHODE-GRID 2	C  - G2
C5   2 3  {CG1G2}   ; Grid 1-GRID 2	G1  - G2
C2   1 3  {CPG1}  ; GRID 1-PLATE	G1 - A                                         
C3   1 4  {CCP}   ; CATHODE-PLATE	A  - C                                        
R1   3 5  {RGI}   ; FOR GRID CURRENT	G1 - 5                                     
D3   5 4  DX      ; FOR GRID CURRENT	5  - C                                     
.MODEL DX D(IS=1N RS=1 CJO=10PF TT=1N)                                          
.ENDS BTetrodeD      

****************************************************                            
****************************************************                            
.SUBCKT BTetrodeDE 1 2 3 4; A G2 G1 C                                            
RE1  7 0  1MEG    ; DUMMY SO NODE 7 HAS 2 CONNECTIONS                           
E1 7 0 VALUE=                                                                   
+{V(2,4)/KP*LOG(1+EXP(KP*(1/MU+V(3,4)/SQRT(KVB+V(2,4)*V(2,4)))))}               
E2   8 0 VALUE = {Ookg1mOokG2 + Aokg1*V(1,4) - alkg1palskg2*Exp(-be*V(1,4)*SQRT(be*V(1,4)))}
E3   9 0 VALUE = {Sc/kG2*V(1,4)*(1+tanh(-ap*(V(1,4)-V(2,4)/lam+w+nu*V(3,4))))}  
G1   1 4 VALUE = {0.5*(PWR(V(7),EX)+PWRS(V(7),EX))*(V(8)-V(9))}                                                                     
G2   2 4 VALUE = {0.5*(PWR(V(7),EX)+PWRS(V(7),EX))/KG2 *(1+als*Exp(-be*V(1,4) * SQRT(be*V(1,4))))}
RCP  1 4  1G      ; FOR CONVERGENCE	A  - C                                      
C1   3 4  {CCG1}   ; CATHODE-GRID 1	C  - G1
C4   2 4  {CCG2}   ; CATHODE-GRID 2	C  - G2
C5   2 3  {CG1G2}   ; Grid 1-GRID 2	G1  - G2
C2   1 3  {CPG1}  ; GRID 1-PLATE	G1 - A                                         
C3   1 4  {CCP}   ; CATHODE-PLATE	A  - C                                        
R1   3 5  {RGI}   ; FOR GRID CURRENT	G1 - 5                                     
D3   5 4  DX      ; FOR GRID CURRENT	5  - C                                     
.MODEL DX D(IS=1N RS=1 CJO=10PF TT=1N)
.ENDS BTetrodeDE                                    

****************************************************                            
****************************************************
.SUBCKT PenthodeVDE 1 2 3 4; A G2 G1 C
*
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
*
RE1  7 0  1MEG    ; DUMMY SO NODE 7 HAS 2 CONNECTIONS
E1   7 0  VALUE=
+{V(2,4)/KP*LOG(1+EXP(KP*(1/MU+V(3,4)/SQRT(KVB+V(2,4)*V(2,4)))))}
E11 17 0  VALUE=
+{V(2,4)/KP*LOG(1+EXP(KP*(1/MUb+V(3,4)/SQRT(KVB+V(2,4)*V(2,4)))))}
E20  9 0  VALUE = {(1-svar)*0.5*(PWR(V(7),EX)+PWRS(V(7),EX))+ svar*0.5*(PWR(V(17),EXb)+PWRS(V(17),EXb))}
E2   8 0 VALUE = {Ookg1mOokG2 + Aokg1*V(1,4) - alkg1palskg2*Exp(-be*V(1,4)*SQRT(be*V(1,4)))}
G1   1 4  VALUE = {V(9)*V(8)}
G2   2 4 VALUE = {V(9)/KG2 *(1+als*Exp(-be*V(1,4) * SQRT(be*V(1,4))))}
RCP  1 4  1G      ; FOR CONVERGENCE	A  - C
C1   3 4  {CCG1}   ; CATHODE-GRID 1	C  - G1
C4   2 4  {CCG2}   ; CATHODE-GRID 2	C  - G2
C5   2 3  {CG1G2}   ; GRID 1 -GRID 2	G1  - G2
C2   1 3  {CPG1}  ; GRID 1-PLATE	G1 - A
C3   1 4  {CCP}   ; CATHODE-PLATE	A  - C
R1   3 5  {RGI}   ; FOR GRID CURRENT	G1 - 5
D3   5 4  DX      ; FOR GRID CURRENT	5  - C
.MODEL DX D(IS=1N RS=1 CJO=10PF TT=1N)
.ENDS PenthodeVDE

****************************************************
****************************************************
.SUBCKT PenthodeVD 1 2 3 4; A G2 G1 C
*
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
*
RE1  7 0  1MEG    ; DUMMY SO NODE 7 HAS 2 CONNECTIONS
E1   7 0  VALUE=
+{V(2,4)/KP*LOG(1+EXP(KP*(1/MU+V(3,4)/SQRT(KVB+V(2,4)*V(2,4)))))}
E11 17 0  VALUE=
+{V(2,4)/KP*LOG(1+EXP(KP*(1/MUb+V(3,4)/SQRT(KVB+V(2,4)*V(2,4)))))}
E20  9 0  VALUE = {(1-svar)*0.5*(PWR(V(7),EX)+PWRS(V(7),EX))+ svar*0.5*(PWR(V(17),EXb)+PWRS(V(17),EXb))}
E2   8 0  VALUE = {Ookg1mOokG2 + Aokg1*V(1,4) - alkg1palskg2/(1 + be*V(1,4))}
G1   1 4  VALUE = {V(9)*V(8)}
G2   2 4  VALUE = {V(9)/KG2 * (1+ als/(1+be*V(1,4)))}
RCP  1 4  1G      ; FOR CONVERGENCE	A  - C
C1   3 4  {CCG1}   ; CATHODE-GRID 1	C  - G1
C4   2 4  {CCG2}   ; CATHODE-GRID 2	C  - G2
C5   2 3  {CG1G2}   ; GRID 1 -GRID 2	G1  - G2
C2   1 3  {CPG1}  ; GRID 1-PLATE	G1 - A
C3   1 4  {CCP}   ; CATHODE-PLATE	A  - C
R1   3 5  {RGI}   ; FOR GRID CURRENT	G1 - 5
D3   5 4  DX      ; FOR GRID CURRENT	5  - C
.MODEL DX D(IS=1N RS=1 CJO=10PF TT=1N)
.ENDS PenthodeVD

****************************************************                            
****************************************************                            
.SUBCKT PenthodeDE 1 2 3 4; A G2 G1 C                                           
RE1  7 0  1MEG    ; DUMMY SO NODE 7 HAS 2 CONNECTIONS                           
E1 7 0 VALUE=                                                                   
+{V(2,4)/KP*LOG(1+EXP(KP*(1/MU+V(3,4)/SQRT(KVB+V(2,4)*V(2,4)))))}
E2   8 0 VALUE = {Ookg1mOokG2 + Aokg1*V(1,4) - alkg1palskg2*Exp(-be*V(1,4)*SQRT(be*V(1,4)))}
G1   1 4  VALUE = {0.5*(PWR(V(7),EX)+PWRS(V(7),EX))*V(8)}                       
G2   2 4 VALUE = {0.5*(PWR(V(7),EX)+PWRS(V(7),EX))/KG2 *(1+als*Exp(-be*V(1,4) * SQRT(be*V(1,4))))}
RCP  1 4  1G      ; FOR CONVERGENCE	A  - C                                      
C1   3 4  {CCG1}   ; CATHODE-GRID 1	C  - G1
C4   2 4  {CCG2}   ; CATHODE-GRID 2	C  - G2
C5   2 3  {CG1G2}   ; Grid 1-GRID 2	G1  - G2
C2   1 3  {CPG1}  ; GRID 1-PLATE	G1 - A                                         
C3   1 4  {CCP}   ; CATHODE-PLATE	A  - C                                        
R1   3 5  {RGI}   ; FOR GRID CURRENT	G1 - 5                                     
D3   5 4  DX      ; FOR GRID CURRENT	5  - C                                     
.MODEL DX D(IS=1N RS=1 CJO=10PF TT=1N)                                          
.ENDS PenthodeDE

****************************************************                            
.SUBCKT PenthodeD 1 2 3 4; A G2 G1 C                                            
RE1  7 0  1MEG    ; DUMMY SO NODE 7 HAS 2 CONNECTIONS                           
E1 7 0 VALUE=                                                                   
+{V(2,4)/KP*LOG(1+EXP(KP*(1/MU+V(3,4)/SQRT(KVB+V(2,4)*V(2,4)))))}               
E2   8 0 VALUE = {Ookg1mOokG2 + Aokg1*V(1,4) - alkg1palskg2/(1 + be*V(1,4))}    
G1   1 4  VALUE = {0.5*(PWR(V(7),EX)+PWRS(V(7),EX))*V(8)}                       
G2   2 4 VALUE = {0.5*(PWR(V(7),EX)+PWRS(V(7),EX))/KG2 * (1+ als/(1+be*V(1,4)))}
RCP  1 4  1G      ; FOR CONVERGENCE	A  - C                                      
C1   3 4  {CCG1}   ; CATHODE-GRID 1	C  - G1
C4   2 4  {CCG2}   ; CATHODE-GRID 2	C  - G2
C5   2 3  {CG1G2}   ; Grid 1-GRID 2	G1  - G2
C2   1 3  {CPG1}  ; GRID 1-PLATE	G1 - A                                         
C3   1 4  {CCP}   ; CATHODE-PLATE	A  - C                                        
R1   3 5  {RGI}   ; FOR GRID CURRENT	G1 - 5                                     
D3   5 4  DX      ; FOR GRID CURRENT	5  - C                                     
.MODEL DX D(IS=1N RS=1 CJO=10PF TT=1N)                                          
.ENDS PenthodeD

****************************************************                            
.SUBCKT TriodeK 1 2 3; A G C                                                    
RE1 7 0 1G                                                                      
E1 7 0 VALUE=                                                                   
+{V(1,3)/KP*LOG(1+EXP(KP*(1/MU+V(2,3)/SQRT(KVB+V(1,3)*V(1,3)))))}               
G1 1 3 VALUE={0.5*(PWR(V(7),EX)+PWRS(V(7),EX))/KG1}                             
RCP 1 3 1G    ; TO AVOID FLOATING NODES IN MU-FOLLOWER                          
C1 2 3 {CCG}  ; CATHODE-GRID                                                    
C2 2 1 {CGP}  ; GRID-PLATE                                                      
C3 1 3 {CCP}  ; CATHODE-PLATE                                                   
D3 5 3 DX     ; FOR GRID CURRENT                                                
R1 2 5 {RGI}  ; FOR GRID CURRENT                                                
.MODEL DX D(IS=1N RS=1 CJO=10PF TT=1N)                                          
.ENDS TriodeK

****************************************************                            
.SUBCKT DiodeK 1 2; A C                                                         
G1   1 2  VALUE = {0.5/k*(PWR(V(1,2)+eps,EX)+PWRS(V(1,2)+eps,EX))}              
C3   1 2  {CCP}   ; CATHODE-PLATE	A  - C                                        
.ENDS DiodeK

   
