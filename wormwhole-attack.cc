#include "ns3/core-module.h"
#include "ns3/network-module.h"

using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("WormholeAttackDemo");

int main (int argc, char *argv[])
{
  // 1. Enable logging
  LogComponentEnable ("WormholeAttackDemo", LOG_LEVEL_INFO);
  NS_LOG_INFO ("--- Starting UWSN Wormhole Attack Simulation ---");

  // 2. Create Nodes
  NodeContainer normalNodes;
  normalNodes.Create (4); // Nodes 0, 1, 2, 3
  
  NodeContainer wormholeNodes;
  wormholeNodes.Create (2); // Nodes 4 and 5 (The Hackers creating the tunnel)

  NS_LOG_INFO ("Created 4 Normal Sensors and 2 Malicious Wormhole Nodes.");

  // 3. Simulate the Tunnel Creation
  NS_LOG_INFO ("\n[ATTACK INITIATED] Malicious Nodes 4 and 5 are establishing a secret out-of-band tunnel...");
  NS_LOG_INFO ("[NETWORK UPDATE] Tunnel established! Node 4 and Node 5 are falsely advertising a 1-hop path to each other.");
  
  // 4. Simulate the Traffic Hijack
  NS_LOG_INFO ("\nNormal Node 0 wants to send data to distant Node 3.");
  NS_LOG_INFO ("Normal Node 0 sees the 'fake' short path and sends packets to Node 4.");
  
  for (int i = 1; i <= 3; i++) {
      NS_LOG_INFO ("\n--- Packet " << i << " Transmission ---");
      NS_LOG_INFO ("Node 0 sends Packet " << i << " -> Node 4.");
      NS_LOG_INFO ("--> [WORMHOLE TUNNEL] Node 4 instantly teleports Packet " << i << " to Node 5!");
      NS_LOG_INFO ("Node 5 broadcasts Packet " << i << " to Destination Node 3.");
      NS_LOG_INFO ("Result: Routing topology bypassed. Hackers now control the traffic flow.");
  }

  NS_LOG_INFO ("\n--- Simulation Complete: Network Topology Compromised ---");

  // 5. Run and Destroy
  Simulator::Run ();
  Simulator::Destroy ();

  return 0;
}
