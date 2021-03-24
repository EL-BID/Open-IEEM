* arg2012cc-data2.inc



DISPLAY "#### START: arg2012cc-data2.inc";    

* start: define additional sets for land use



* land01 signals if land use data is empty or not 
$SETGLOBAL land01 1



$ONMULTI

SET
  lnd 
  /
fortot  
fornprod
forplant
agrtot
crops
livestock
  /
  
  lndfortot
  /
fortot  
  /
  
  lndfornprod
  /
fornprod  
  /
  
  lndforplant
  /
forplant  
  /
  
  lndagrtot
  /
agrtot  
  /
  
  lndcro
  /
crops  
  /
  
  lndliv  
  /
livestock  
  /

mfforlndforplant
  /
f-forestry.forplant
  /

mlndfornprodlndforplant
  /
fornprod.forplant
  /

mlndfornprodlndfortot
  /
fornprod.fortot
  /

mlndforplantlndfortot
  /
forplant.fortot
  /

mflandlndcro
  /
f-land-crops.crops
  /

mflandlndliv
  /
f-land-livestock.livestock
  /

mlndcrolndagrtot
  /
crops.agrtot
  /

mlndlivlndagrtot
  /
livestock.agrtot
  /

mflandlndfortot
  /
f-land-crops.fortot
f-land-livestock.fortot

  /
;  



$ONTEXT
$LOADDC lnd
$LOADDC lndfortot
$LOADDC lndfornprod
$LOADDC lndforplant
$LOADDC lndagrtot
$LOADDC lndcro
$LOADDC lndliv
$LOADDC mfforlndforplant
$LOADDC mlndfornprodlndforplant
$LOADDC mlndfornprodlndfortot
$LOADDC mlndforplantlndfortot
$LOADDC mflandlndcro
$LOADDC mflandlndliv
$LOADDC mlndcrolndagrtot
$LOADDC mlndlivlndagrtot
$LOADDC mflandlndfortot
$OFFTEXT

$LOADDC qfor0

$OFFMULTI



* end: define additional sets for land use



* start: split land payments between crops and livestock

PARAMETER
  balchk(ac)       to check sam balance
;

SET 
  acrodum(ac)
  /
  a-crops
  /
  alivdum(ac)
  /
  a-livestock
  /

PARAMETER
  ylandshr(ac)
;
ylandshr(acnt) = SAM(acnt,'f-land')/SUM(acntp, SAM(acntp,'f-land'));


SAM('f-land-crops',acrodum) = SAM('f-land',acrodum);
SAM(acnt,'f-land-crops') = SUM(acrodum, SAM('f-land-crops',acrodum))*ylandshr(acnt);

SAM('f-land-livestock',aliv) = SAM('f-land',aliv);
SAM(acnt,'f-land-livestock') = SUM(a, SAM('f-land-livestock',a))*ylandshr(acnt);

SAM('f-land',ac) = 0;
SAM(ac,'f-land') = 0;

* check sam consistency
SAM('total',acnt) = SUM(acntp, SAM(acntp,acnt));
SAM(acnt,'total') = SUM(acntp, SAM(acnt,acntp));
balchk(acnt) = SAM('total',acnt) - SAM(acnt,'total');
DISPLAY balchk;


* end: split land payments between crops and livestock


DISPLAY "#### END: arg2012cc-data2.inc";    


