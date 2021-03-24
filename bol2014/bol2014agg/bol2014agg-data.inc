* bol2014agg-data.inc



* Read data from excel file
$CALL 'GDXXRW i=bol2014agg-data.xlsx o=bol2014agg-data.gdx index=layout!A1'
$GDXIN bol2014agg-data.gdx

* start: IMv2

$LOADDC t
$LOADDC t2=tsol



* end: IMv2