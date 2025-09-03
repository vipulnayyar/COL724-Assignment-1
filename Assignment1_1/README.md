# COL724-Assignment 1-1

Place source files in ```<NS3-DIR>/scratch```

## Build All
```
$ cd <NS3-DIR>
$ ./ns3 build
```

## Run BGP Part A

Source Code : bgp.cc(unchanged)

```
$ NS_LOG="*=prefix_time|prefix_node|prefix_level:Ipv4L3Protocol=level_logic|prefix_time|prefix_node|prefix_level" ./build/scratch/ns3.45-bgp-default
```

Log : bgplite.log
Console excerpt : bgplite-screenshot.png
XML : bgp-lite-results.xml


## Run BGP Part B

Source Code : bgp_partB.cc

```
$ NS_LOG="*=prefix_time|prefix_node|prefix_level:Ipv4L3Protocol=level_logic|prefix_time|prefix_node|prefix_level" ./build/scratch/ns3.45-bgp_partB-default
```

Log : bgp_partB.log
Console excerpt : bgp_partB-screenshot.png
XML : bgp-partB-results.xml

## Run BGP Part C

Source Code : bgp_partC.cc

```
$ NS_LOG="*=prefix_time|prefix_node|prefix_level:Ipv4L3Protocol=level_logic|prefix_time|prefix_node|prefix_level" ./build/scratch/ns3.45-bgp_partC-default
```

Log : bgp_partC.log
Console excerpt : bgp_partC-screenshot.png
XML : bgp-partC-results.xml
