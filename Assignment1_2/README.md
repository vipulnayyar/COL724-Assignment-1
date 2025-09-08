# COL724-Assignment 1-1


## Build All
Place source files in ```<NS3-DIR>/scratch```

```
$ cd <NS3-DIR>
$ ./ns3 build
```

## Run BGP Part D

Source Code : partD/bgp_partD.cc

```
$ NS_LOG="*=prefix_time|prefix_node|prefix_level:Ipv4L3Protocol=level_function|prefix_time|prefix_node|prefix_level" ./build/scratch/ns3.45-bgp_partD-default 2>&1 | grep -Ev "Ipv4L3Protocol:Send|Ipv4L3Protocol:BuildHeader|Ipv4L3Protocol:LocalDeliver|Ipv4L3Protocol:Receive"
```

Log : partD/bgp_partD.log

Console excerpt : bgp_partD-screenshot.png

XML : bgp-partD-results.xml

Route files:

## Run BGP Part E

Source Code : bgp_partE.cc

```
$ NS_LOG="*=prefix_time|prefix_node|prefix_level:Ipv4L3Protocol=level_function|prefix_time|prefix_node|prefix_level" ./build/scratch/ns3.45-bgp_partE-default 2>&1 | grep -Ev "Ipv4L3Protocol:Send|Ipv4L3Protocol:BuildHeader|Ipv4L3Protocol:LocalDeliver|Ipv4L3Protocol:Receive"
```

Log : partE/bgp_partE.log

Console excerpt : partE/bgp_partE-screenshot.png

XML : partE/bgp-partE-results.xml

Route files:
