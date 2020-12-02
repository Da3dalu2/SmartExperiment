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