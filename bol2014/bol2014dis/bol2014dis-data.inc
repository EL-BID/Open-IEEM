* bol2014dis-data.inc



* Read data from excel file
$CALL 'GDXXRW i=bol2014dis-data.xlsx o=bol2014dis-data.gdx index=layout!A1'
$GDXIN bol2014dis-data.gdx

* start: IMv2

$LOADDC t
$LOADDC t2=tsol



* end: IMv2