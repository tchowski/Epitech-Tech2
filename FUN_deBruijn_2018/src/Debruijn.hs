--
-- EPITECH PROJECT, 2019
-- deBruijn
-- File description:
-- deBruijn
--
module Debruijn where

import Args
import Control.Monad
import Data.Char
import Data.List (isInfixOf)
import Data.List
import Data.List hiding (words)
import Data.List (intercalate)
import System.Exit
import Text.Read

list_to_string = unwords . map show

first_fit :: Int -> IO ()
first_fit n = putStrLn $ list_to_string $ ["001", "0002", "000"]

list = []

put_list a = list ++ [a]

lenght_sequence x = x ^ 2

-- sequence_debruinj :: Int -> Int
sequence_debruinj a = replicateM a "01"

show' :: Show a => [a] -> String
show' = intercalate "" . map show

debruinj2 :: Int -> [Int]
debruinj2 argument =
  iterate replique (replicate argument 0) !! (2 ^ argument)
  where
    replique list_sequence =
      if take argument (1 : list_sequence) `isInfixOf` list_sequence
        then (0 : list_sequence)
        else (1 : list_sequence)

-- Regarde si les nth element existe déjà dans la liste en ajoutant 1 à la liste
-- take : nth elements (début -> n) Int -> [a] -> [a]

-- iterate : Crée une liste infinie en applicant le résultat
-- précedement calculé 	(a -> a) -> a -> [a]

-- replicate : Crée une liste de n elements replicate n * element
-- Int -> a -> [a]

debruijn :: [String] -> String
debruijn (args) = do
  let intargs = head args
  case readMaybe intargs :: Maybe Int of
    Just x -> if x > 0 then show' $ debruinj2 x else []
    Nothing -> []

check_args :: [String] -> IO()
check_args (args) = do
  let intargs = head args
  case readMaybe intargs :: Maybe Int of
    Just x -> if x > 0 then check args else do putStrLn usage ; exitWith (ExitFailure 84)
    Nothing -> do putStrLn usage ; exitWith (ExitFailure 84)

check_clean :: [String] -> IO()
check_clean (args) = do
  let intargs = head args
  case readMaybe intargs :: Maybe Int of
    Just x -> if x > 0 then clean args else do putStrLn usage ; exitWith (ExitFailure 84)
    Nothing -> do putStrLn usage ; exitWith (ExitFailure 84)

check_unique :: [String] -> IO()
check_unique (args) = do
  let intargs = head args
  case readMaybe intargs :: Maybe Int of
    Just x -> if x > 0 then unique args else do putStrLn usage ; exitWith (ExitFailure 84)
    Nothing -> do putStrLn usage ; exitWith (ExitFailure 84)

check (args) = do
  name <- getLine
  let sort_input = sort name
  let intargs = head args
  let int = read intargs :: Int
  let debruinj_sorted = sort $ show' $ debruinj2 int
  if isSubsequenceOf debruinj_sorted sort_input == False
    then putStrLn $ id "KO"
    else if 2 ^ int /= length sort_input
          then do
            putStrLn $ id "KO"
          else putStrLn $ id "OK"

unique (args) = do
  name1 <- getLine
  name2 <- getLine
  let sort_input1 = sort name1
  let sort_input2 = sort name2
  let intargs = head args
  let int = read intargs :: Int
  let debruinj_sorted = sort $ show' $ debruinj2 int
  if isSubsequenceOf debruinj_sorted sort_input1 == False ||
     isSubsequenceOf debruinj_sorted sort_input2 == False
    then putStrLn $ id "KO"
    else if 2 ^ int /= length sort_input1 || 2 ^ int /= length sort_input2
           then putStrLn $ id "KO"
           else if isSubsequenceOf sort_input1 sort_input2 == False
                  then putStrLn $ id "KO"
            else if isSubsequenceOf (reverse name1) name2 == True
                  then putStrLn $ id "KO"
                  else putStrLn $ id "OK"

clean (args) = go ""
  where
    go contents = do
      line <- getLine
      let sort_input = sort line
      let intargs = head args
      let int = read intargs :: Int
      let debruinj_sorted = sort $ show' $ debruinj2 int
      if line == "END"
        then do
          putStr contents
        else if isSubsequenceOf debruinj_sorted sort_input &&
                2 ^ int == length sort_input && isInfixOf (reverse line) contents == False
               then do
                 go (contents ++ line ++ "\n")
               else go (contents)