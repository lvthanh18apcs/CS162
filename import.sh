#!/bin/sh

path="data/$1_list"

rm -f ${path}
rm -r -f data/classes/*

ls data/init/$1 | while read fname
do
    echo ${fname%%.csv} >> ${path}
done