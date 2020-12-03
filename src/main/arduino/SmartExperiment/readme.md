# Available tasks

- DetectStartButtonPress
- DetectEndButtonPress
- DisplayStatus
- ComputeData
- SendData
- DetectObjectDistance
- DetectObjectPresence
- DetectMotion
- DisplaySpeed
- SetSamplingFrequency
- UpdateStatus

# Distribution of tasks among states [Ordered]

Always: UpdateStatus and DisplayStatus

## Ready

+ DetectStartButtonPress
+ DetectObjectPresence
+ SetSamplingFrequency

## Running

+ DetectEndButtonPress
+ DetectObjectDistance
+ ComputeData
+ SendData
+ DisplaySpeed

## Ending

No additional tasks required

## Suspended

+ DetectMotion

# Useful links

https://github.com/jfree/jfreechart | jfree/jfreechart: A 2D chart library for Java applications (JavaFX, Swing or server-side).
https://www.jfree.org/jfreechart/ | JFreeChart
https://jfree.github.io/jfreechart-and-opencsv/ | JFreeChart and OpenCSV – David Gilbert – Java Developer / Creator of http://www.jfree.org
https://github.com/jfree/jfreechart-fx | jfree/jfreechart-fx: Extensions for JFreeChart to support JavaFX client applications.
https://www.jfree.org/jfreechart/javadoc/org/jfree/data/time/DynamicTimeSeriesCollection.html | DynamicTimeSeriesCollection (JFreeChart 1.5.1 API)
https://github.com/jfree/jfree-fxdemos/blob/master/src/main/java/org/jfree/chart/fx/demo/TimeSeriesChartFXDemo1.java | jfree-fxdemos/TimeSeriesChartFXDemo1.java at master · jfree/jfree-fxdemos
https://www.tutorialspoint.com/jfreechart/jfreechart_timeseries_chart.htm | JFreeChart - TimeSeries Chart - Tutorialspoint
https://duckduckgo.com/?t=ffab&q=curriculum+vitae+et+studiorum&ia=web | curriculum vitae et studiorum at DuckDuckGo