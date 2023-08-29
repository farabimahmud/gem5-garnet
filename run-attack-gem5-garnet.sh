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
    --destination-list=8,53 \


    # --debug-flags=Vanilla,Vanilla_X86 \
    # --debug-file=debug.out \
    # --target-latency=80 \
    # --max-hpc=5 \
    # --upper-limit=80 \
