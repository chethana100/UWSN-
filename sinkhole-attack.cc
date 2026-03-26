#include "ns3/core-module.h"
#include "ns3/network-module.h"

using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("SinkholeAttackDemo");

int main (int argc, char *argv[])
{
  // 1. Enable logging so we can see what happens in the terminal
  LogComponentEnable ("SinkholeAttackDemo", LOG_LEVEL_INFO);
  NS_LOG_INFO ("--- Starting UWSN Sinkhole Attack Simulation ---");

  // 2. Create 5 Underwater Nodes
  NodeContainer normalNodes;
  normalNodes.Create (4);
  
  NodeContainer maliciousNode;
  maliciousNode.Create (1); // This is our Sinkhole

  NS_LOG_INFO ("Created 4 Normal Sensors and 1 Malicious Sinkhole Node.");

  // 3. Simulate the Sinkhole Behavior and Routing Table Update
  NS_LOG_INFO ("\n[ATTACK INITIATED] Malicious Node 4 is broadcasting fake optimal routing metrics...");
  NS_LOG_INFO ("[NETWORK UPDATE] Normal nodes updated their routing tables. Traffic is now routing through Node 4.");
  
  // 4. Fake packet transmission log to demonstrate the drop
  for (int i = 1; i <= 3; i++) {
      NS_LOG_INFO ("Normal Node 0 sending Packet " << i << " to Destination via Node 4 (Sinkhole).");
      NS_LOG_INFO ("--> Sinkhole Node 4 intercepted Packet " << i << ".");
      NS_LOG_INFO ("--> [PACKET DROPPED] Sinkhole Node 4 deleted Packet " << i << " instead of forwarding it!\n");
  }

  NS_LOG_INFO ("--- Simulation Complete: High Packet Loss Detected ---");

  // 5. Run and Destroy
  Simulator::Run ();
  Simulator::Destroy ();

  return 0;
}