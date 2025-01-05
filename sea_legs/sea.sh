#!/bin/bash
../out/Release/node --experimental-sea-config sea-config.json
cp ../out/Release/node demo
npx postject demo NODE_SEA_BLOB demo.blob --sentinel-fuse NODE_SEA_FUSE_fce680ab2cc467b6e072b8b5df1996b2
rm -f demo.blob
