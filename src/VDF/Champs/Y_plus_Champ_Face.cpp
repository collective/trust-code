/****************************************************************************
* Copyright (c) 2023, CEA
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
* 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
* 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
* OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*****************************************************************************/

#include <Y_plus_Champ_Face.h>
#include <Champ_Face_VDF.h>
#include <Domaine_Cl_VDF.h>

Implemente_instanciable(Y_plus_Champ_Face, "Y_plus_Champ_Face", Champ_Fonc_P0_VDF);

Sortie& Y_plus_Champ_Face::printOn(Sortie& s) const { return s << que_suis_je() << " " << le_nom(); }

Entree& Y_plus_Champ_Face::readOn(Entree& s) { return s; }

void Y_plus_Champ_Face::associer_champ(const Champ_Face_VDF& un_champ)
{
  mon_champ_ = un_champ;
}

void Y_plus_Champ_Face::me_calculer(double tps)
{
  mon_champ_->calcul_y_plus(valeurs(), le_dom_Cl_VDF.valeur());
}

const Domaine_Cl_dis_base& Y_plus_Champ_Face::domaine_Cl_dis_base() const
{
  return le_dom_Cl_VDF.valeur();
}

void Y_plus_Champ_Face::mettre_a_jour(double tps)
{
  me_calculer(tps);
  changer_temps(tps);
  Champ_Fonc_base::mettre_a_jour(tps);
}
