# COL724-Assignment 1-1


## Build All
Place source files in ```<NS3-DIR>/scratch```

```
$ cd <NS3-DIR>
$ ./ns3 build
```

## Run BGP Part D

Source Code : bgp_partD.cc

```
$ NS_LOG="*=prefix_time|prefix_node|prefix_level:Ipv4L3Protocol=level_logic|prefix_time|prefix_node|prefix_level" ./build/scratch/ns3.45-bgp_partD-default
```

Log : bgp_partD.log

Console excerpt : bgp_partD-screenshot.png

XML : bgp-partD-results.xml


## Run BGP Part E

Source Code : bgp_partE.cc

```
$ NS_LOG="*=prefix_time|prefix_node|prefix_level:Ipv4L3Protocol=level_logic|prefix_time|prefix_node|prefix_level" ./build/scratch/ns3.45-bgp_partE-default
```

Log : bgp_partE.log

Console excerpt : bgp_partE-screenshot.png

XML : bgp-partE-results.xml

