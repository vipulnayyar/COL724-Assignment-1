#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"
#include "ns3/flow-monitor-module.h"
//#include "ns3/ipv4-static-routing-helper.h"
#include "ns3/aodv-helper.h"

using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("BgpPartDExample");


void StopLinkInterface(Ptr<Node> router1, int32_t interface_index1, Ptr<Node> router2, int32_t interface_index2){
  
  router1->GetObject<Ipv4>()->SetDown(interface_index1);
  router2->GetObject<Ipv4>()->SetDown(interface_index2);

}

void StartLinkInterface(Ptr<Node> router1, int32_t interface_index1, Ptr<Node> router2, int32_t interface_index2){
  router1->GetObject<Ipv4>()->SetUp(interface_index1);
  router2->GetObject<Ipv4>()->SetUp(interface_index2);
}

void SaveSnapshot(Ptr<FlowMonitor> monitor, std::string filename){
  monitor->CheckForLostPackets();
  monitor->SerializeToXmlFile(filename, true, true);
  monitor->ResetAllStats();
}

int main (int argc, char *argv[])
{
  Time::SetResolution (Time::NS);
  CommandLine cmd;
  cmd.Parse (argc, argv);

  LogComponentEnable ("BgpPartDExample", LOG_LEVEL_INFO);
  LogComponentEnable ("UdpEchoClientApplication", LOG_LEVEL_INFO);
  LogComponentEnable ("UdpEchoServerApplication", LOG_LEVEL_INFO);

  NS_LOG_INFO ("Starting BGP-part-D style simulation with 3 routers...");

  Config::SetDefault("ns3::Ipv4GlobalRouting::RespondToInterfaceEvents", BooleanValue(true));

  NodeContainer routers;
  routers.Create (3);

  AodvHelper aodv;
    
  Ipv4ListRoutingHelper list; 
  list.Add (aodv, 0);

  InternetStackHelper internet;
  internet.SetRoutingHelper(list);
  internet.Install (routers);

  PointToPointHelper p2p;
  p2p.SetDeviceAttribute ("DataRate", StringValue ("10Mbps"));
  p2p.SetChannelAttribute ("Delay", StringValue ("2ms"));


  NetDeviceContainer d12 = p2p.Install (routers.Get (0), routers.Get (1));
  NetDeviceContainer d23 = p2p.Install (routers.Get (1), routers.Get (2));
  NetDeviceContainer d13 = p2p.Install (routers.Get (0), routers.Get (2));


  Ipv4AddressHelper ipv4;
  ipv4.SetBase ("10.0.1.0", "255.255.255.0");
  Ipv4InterfaceContainer i12 = ipv4.Assign (d12);

  ipv4.SetBase ("10.0.2.0", "255.255.255.0");
  Ipv4InterfaceContainer i23 = ipv4.Assign (d23);

  ipv4.SetBase ("10.0.3.0", "255.255.255.0");
  Ipv4InterfaceContainer i13 = ipv4.Assign (d13);

  Ipv4GlobalRoutingHelper::PopulateRoutingTables ();


  uint16_t port = 9;
  UdpEchoServerHelper server (port);
  ApplicationContainer apps = server.Install (routers.Get (2));
  apps.Start (Seconds (1.0));
  apps.Stop (Seconds (10.0));

  UdpEchoClientHelper client (i23.GetAddress (1), port);
  client.SetAttribute ("MaxPackets", UintegerValue (10));
  client.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
  client.SetAttribute ("PacketSize", UintegerValue (1024));

  apps = client.Install (routers.Get (0));
  apps.Start (Seconds (2.0));
  apps.Stop (Seconds (10.0));

  Ptr<Ipv4> router0 = routers.Get(0)->GetObject<Ipv4>();
  int32_t router0_interface2 = router0->GetInterfaceForDevice(d13.Get(0));

  Ptr<Ipv4> router2 = routers.Get(2)->GetObject<Ipv4>();
  int32_t router2_interface2 = router2->GetInterfaceForDevice(d13.Get(1));


  Simulator::Schedule(Seconds(5.0), &StopLinkInterface, routers.Get(0), router0_interface2, routers.Get(2), router2_interface2 );

  Simulator::Schedule(Seconds(7.0), &StartLinkInterface, routers.Get(0), router0_interface2, routers.Get(2), router2_interface2 );

  FlowMonitorHelper flowmon;
  Ptr<FlowMonitor> monitor = flowmon.InstallAll ();

  Simulator::Schedule(Seconds(5.0), &SaveSnapshot, monitor, "bgp-partD-before-failure-results.xml");

  Simulator::Schedule(Seconds(7.0), &SaveSnapshot, monitor, "bgp-partD-during-failure-results.xml");


  Ptr<OutputStreamWrapper> routing_stream1 = Create<OutputStreamWrapper>("partD-aodv-routing-before-failure-4s.routes", std::ios::out);
  Ipv4RoutingHelper::PrintRoutingTableAllAt(Seconds(4), routing_stream1);

  Ptr<OutputStreamWrapper> routing_stream2 = Create<OutputStreamWrapper>("partD-aodv-routing-during-failure-6s.routes", std::ios::out);
  Ipv4RoutingHelper::PrintRoutingTableAllAt(Seconds(6), routing_stream2);

  Ptr<OutputStreamWrapper> routing_stream3 = Create<OutputStreamWrapper>("partD-aodv-routing-after-failure-8s.routes", std::ios::out);
  Ipv4RoutingHelper::PrintRoutingTableAllAt(Seconds(8), routing_stream3);

  

  Simulator::Stop (Seconds (11.0));
  Simulator::Run ();

  monitor->SerializeToXmlFile("bgp-partD-after-failure-results.xml", true, true);

  Simulator::Destroy ();
  return 0;
}

