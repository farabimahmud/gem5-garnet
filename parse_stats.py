import numpy as np 
import pandas as pd 

def get_closest_dest_data(filename):
  with open(filename,'r') as f:
    for line in f.readlines():
      if line.startswith("system.ruby.network.closest_dest_attack_packet_latency |"):
        tokens = line.split("|")[1:]
        x = []
        for token in tokens:
          elems = token.strip().split(" ")
          
          for elem in elems:
            if elem != '':
              x.extend([elem])

        x = x[1::3]
        data = [float(e[:-1]) for e in x]
  return data 

def get_farthest_dest_data(filename):
  with open(filename,'r') as f:
    for line in f.readlines():
      if line.startswith("system.ruby.network.farthest_dest_attack_packet_latency |"):
        tokens = line.split("|")[1:]
        x = []
        for token in tokens:
          elems = token.strip().split(" ")
          
          for elem in elems:
            if elem != '':
              x.extend([elem])

        x = x[1::3]
        data = [float(e[:-1]) for e in x]
  return data 

if __name__ == "__main__":
  filename = "baseline/stats.txt"
  closest = get_closest_dest_data(filename)
  farthest = get_farthest_dest_data(filename)
  buckets = np.arange(start=0.0,stop=101.0,step=5.00).astype(float)
  print(len(closest), len(farthest), len(buckets))
  df = pd.DataFrame({
    'RTT' : buckets,
    'Farthest' : farthest,
    'Closest' : closest,
  }
  )
  # print(closest,farthest,buckets)
  df.to_csv("data.csv",index=None)
  
  