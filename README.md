# Generating Frequency vs RTT for Simulated Attack
We will use Gem5 with Garnet Synthetic network simulator to obtain this result

## Get Gem5 Code
Clone this repository 
```
git clone https://github.com/farabimahmud/gem5-garnet
```
This is based on the Gem5 v20.0.0.0 release.

Or alternatively, you can download the Gem5 from the gem5 official repository - https://github.com/gem5/gem5/archive/refs/tags/v20.0.0.0.zip


## Build Gem5 
First build the simulator using the following command 
```
./garnetbuild.sh 
```
Alternatively, you can execute the following also directly
```
python3 -m `which scons` build/NULL/gem5.debug -j12 PROTOCOL=Garnet_standalone
```
The detailed process to setup Gem5 can be found in their [Official Gem5 Website](https://www.gem5.org/). 

## Running the attack using Gem5 configuration
To run the attack in Gem5 simulator you can use the `run-attack-gem5-garnet.sh` file. 
It contains the current configuration for the Gem5 simulator and also specifies the attack.


Here is the detailed script for the gem5. This will run one round of timing which might take ~1 Hour in a 3GHz PC. 
```
#!/bin/bash
./build/NULL/gem5.debug \
    --outdir=$PWD/baseline \
    configs/example/garnet_synth_traffic.py \
    --num-cpus=64 \
    --num-dirs=64 \
    --network=garnet2.0 \
    --topology=Mesh_XY \
    --mesh-row=8 \
    --sim-cycles=1000000 \
    --synthetic=uniform_random \
    --bypass=bypass_none \
    --injectionrate=0.001 \
    --attack-enabled \
    --attack-node=0 \
    --attack-rate=1 \
    --garnet-deadlock-threshold=100000 \
    --destination-list=8,53
```
Here we are trying to calculate round trip time for packets from Node 0 to Node 8 and also from Node 0 to Node 53 
This will create the output in `baseline` folder in the current directory

## Parsing the Results 
To parse the results we need to run the `parse_stats.py` file. This requires numpy and pandas package to be installed. 
We need to make sure the proper address to the stat file is given. 

## Plotting the Results 
You should be able to plot the result by using the script `10-Frequency-vs-Round_Trip_Latency/plot.py` with trivial modifications needed from the system. 
Make sure to set the thresholds accordingly. 