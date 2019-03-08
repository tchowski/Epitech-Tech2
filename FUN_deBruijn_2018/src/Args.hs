module Args where
    -- usage :: String

usage = do "USAGE: ./deBruijn n [a] [--check|--unique|--clean]\n\n"
        ++ "      --check       check if a sequence is a de Bruijn sequence\n"
        ++ "      --unique      check if 2 sequences are distinct de Bruijn sequences\n"
        ++ "      --clean       list cleaning\n"
        ++ "      n             order of the sequence\n"
        ++ "      a             alphabet [def: “01”]"