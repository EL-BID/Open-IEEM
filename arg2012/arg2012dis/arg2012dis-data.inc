* arg2012-data.inc



* Read data from excel file
$CALL 'GDXXRW i=arg2012-data.xlsx o=arg2012-data.gdx index=layout!A1'
$GDXIN arg2012-data.gdx

* start: IMv2

$LOADDC t
$LOADDC t2=tsol



* end: IMv2