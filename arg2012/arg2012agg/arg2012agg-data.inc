* arg2012agg-data.inc



* Read data from excel file
$CALL 'GDXXRW i=arg2012agg-data.xlsx o=arg2012agg-data.gdx index=layout!A1'
$GDXIN arg2012agg-data.gdx

* start: IMv2

$LOADDC t
$LOADDC t2=tsol



* end: IMv2