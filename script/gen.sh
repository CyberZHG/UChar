#!/usr/bin/env bash
./get_data.sh
./gen_header_open.py
./gen_code_value.py
./gen_general_category.py
./gen_cases.py
./gen_canonical_combining_class.py
./gen_manual.py
./gen_header_close.py
