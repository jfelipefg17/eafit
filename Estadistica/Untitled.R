###MI PRIMER SCRIPT DE R PARA ESTADISTICA###
##CARGAR LIBRERIA##
library(MASS)
library(readxl)
###CARGAR BASE DE DATOS###
Info_clientes_banco <- read_excel("Desktop/Estadistica/Info_clientes_banco.xlsx")
View(Info_clientes_banco) 
###REENOMBRAMOS LA BASE###
base=Info_clientes_banco
###DESCRIPCION DE LA BASE DE DATOS###
s1=summary(base)
s1