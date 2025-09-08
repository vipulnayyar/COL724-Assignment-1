# COL724-Assignment 1-2


## Build All
Place source files in ```<NS3-DIR>/scratch```

```
$ cd <NS3-DIR>
$ ./ns3 build
```

## Run BGP Part D

**Source Code:** partD/bgp_partD.cc

```
$ NS_LOG="*=prefix_time|prefix_node|prefix_level:Ipv4L3Protocol=level_function|prefix_time|prefix_node|prefix_level" ./build/scratch/ns3.45-bgp_partD-default 2>&1 | grep -Ev "Ipv4L3Protocol:Send|Ipv4L3Protocol:BuildHeader|Ipv4L3Protocol:LocalDeliver|Ipv4L3Protocol:Receive"
```

**Log:** partD/bgp_partD.log

**Console excerpt:** partD-console-excerpt.png

**XML:**

bgp-partD-before-failure-results.xml		

bgp-partD-during-failure-results.xml

bgp-partD-after-failure-results.xml		

**Route files:**

partD-aodv-routing-before-failure-4s.routes

partD-aodv-routing-during-failure-6s.routes

partD-aodv-routing-after-failure-8s.routes

## Run BGP Part E

**Source Code:** partE/bgp_partE.cc

```
$ NS_LOG="*=prefix_time|prefix_node|prefix_level:Ipv4L3Protocol=level_function|prefix_time|prefix_node|prefix_level" ./build/scratch/ns3.45-bgp_partE-default 2>&1 | grep -Ev "Ipv4L3Protocol:Send|Ipv4L3Protocol:BuildHeader|Ipv4L3Protocol:LocalDeliver|Ipv4L3Protocol:Receive"
```

**Log:** partE/bgp_partE.log

**Console excerpt:** partE/partE-console-excerpt.png

**XML:**

bgp-partE-before-failure-results.xml

bgp-partE-during-failure-results.xml

bgp-partE-after-failure-results.xml

**Route files:**

partE-aodv-routing-before-failure-4s.routes

partE-aodv-routing-during-failure-5s.routes

partE-aodv-routing-during-failure-6.5s.routes
partE-aodv-routing-after-failure-8s.routes


