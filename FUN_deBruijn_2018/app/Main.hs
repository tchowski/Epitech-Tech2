--
-- EPITECH PROJECT, 2019
-- main
-- File description:
-- Main
--

module Main (main) where
  import Control.Monad
  import Data.Foldable (foldlM)
  import System.Console.GetOpt
  import System.Environment (getArgs, getProgName)
  import System.Exit
  import Args
  import Debruijn
  import Text.Read
  import Data.Maybe

  main :: IO ()
  main = do
    args <- getArgs
    let intargs = head args
    case args of
        [] -> putStrLn usage
        [_] -> do if null $ debruijn args then
                    do putStrLn usage ; exitWith (ExitFailure 84)
                    else putStrLn $ id debruijn args
        [_,"--check"] -> check_args args
        [_,_,"--check"] -> check_args args
        [_,"--unique"] -> check_unique args
        [_,_,"--unique"] -> check_unique args
        [_,"--clean"] -> check_clean args
        [_,_,"--clean"] -> check_clean args
        otherwise -> do putStrLn usage ; exitWith (ExitFailure 84)