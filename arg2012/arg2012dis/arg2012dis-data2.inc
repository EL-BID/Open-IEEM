* chl2016des-data2.inc



DISPLAY "#### START: chl2016des-data2.inc";    

* fix illegal sam payment
SAM('f-lab','a-domest') = SAM('f-lab','a-domest') + SAM('f-cap','a-domest');
SAM('hhd','f-lab')      = SAM('hhd','f-lab') + SAM('f-cap','a-domest');
SAM('hhd','f-cap')      = SAM('hhd','f-cap') - SAM('f-cap','a-domest');
SAM('f-cap','a-domest') = 0;

PARAMETER
  balchk(ac)       to check sam balance
  errbalchk(ac)	   error sam no balanceada
;

* check sam consistency
SAM('total',acnt) = SUM(acntp, SAM(acntp,acnt));
SAM(acnt,'total') = SUM(acntp, SAM(acnt,acntp));
balchk(acnt) = SAM('total',acnt) - SAM(acnt,'total');
DISPLAY balchk;
errbalchk(ac)$(ABS(balchk(ac)) > 1e-4) = 1/0;
DISPLAY errbalchk;


DISPLAY "#### END: chl2016des-data2.inc";    




