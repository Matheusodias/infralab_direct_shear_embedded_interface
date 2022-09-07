#include "inc/calculatedvariables.h"
#include "inc/experiment.h"
CalculatedVariables::CalculatedVariables()
{
    variables = new Experiment();
}

void CalculatedVariables::calculateValues()
{



}


//apenas no final insere os dados na classe
//porém para fazer os cálculos, alguns dos dados são necessários previamente

//1- Inserir todos os dados na classe ao preencher o campo
//2- Inserir os dados na classe apenas no final e quando precisar de um dado pegar diretamente do campo de texto
//3- Inserir na classe apenas os campos utilizados para cálculos

// Opção 2 escolhida

//dados necessários
//diameter
//initial_height
//initial_wet_weigth
//initial_moisture
//spgr_solids
