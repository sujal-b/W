import socket

# DNS mapping (static)
dns_table = {
    "www.google.com": "142.250.190.68",
    "www.yahoo.com": "98.137.11.163",
    "www.dypitpune.edu.in": "192.168.1.100",
    "192.168.1.100": "www.dypitpune.edu.in",
    "142.250.190.68": "www.google.com"
}

# Create UDP socket
server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server.bind(('localhost', 12345))
print("DNS Server started... waiting for queries")

while True:
    data, addr = server.recvfrom(4096)
    query = data.decode().strip()
    print(f"Received query: {query}")
    
    # Resolve query
    response = dns_table.get(query, "No record found")
    
    # Send response to client
    server.sendto(response.encode(), addr)
    print(f"Sent response: {response}\n")