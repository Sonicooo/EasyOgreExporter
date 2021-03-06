////////////////////////////////////////////////////////////////////////////////
// ExMaterialSet.h
// Author   : Bastien BOURINEAU
// Start Date : January 21, 2012
////////////////////////////////////////////////////////////////////////////////
/*********************************************************************************
*                                                                                *
*   This program is free software; you can redistribute it and/or modify         *
*   it under the terms of the GNU Lesser General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or            *
*   (at your option) any later version.                                          *
*                                                                                *
**********************************************************************************/
////////////////////////////////////////////////////////////////////////////////
// Port to 3D Studio Max - Modified original version
// Author	      : Doug Perkowski - OC3 Entertainment, Inc.
// From work of : Francesco Giordana
// Start Date   : December 10th, 2007
////////////////////////////////////////////////////////////////////////////////

#ifndef _EXMATERIALSET_H
#define _EXMATERIALSET_H

#include "ExShader.h"
#include "ExTools.h"
#include "ExPrerequisites.h"
#include "EasyOgreExporterLog.h"

namespace EasyOgreExporter
{
	class ExMaterialSet
	{
  public:
  private:
		std::vector<ExMaterial*> m_materials;
    std::vector<std::string> m_textures;
    std::vector<ExShader*> m_Shaders;
    ExMaterial* m_default;
  protected:

	public:
		//constructor
		ExMaterialSet(ExOgreConverter* converter);

		//destructor
		~ExMaterialSet();

		//clear
		void clear();

    bool getTextureSameFileNameExist(std::string filepath, std::string name);

    std::string getUniqueTextureName(std::string filepath);

    ExMaterial* getMaterialByName(std::string name);

		//add material
		void addMaterial(ExMaterial* pMat = 0);

		//get material
		ExMaterial* getMaterial(IGameMaterial* pGameMaterial);
		
		//write materials to Ogre Script
		bool writeOgreScript(ParamList &params);
  private:
    ExShader* getShader(std::string& name);
    void addShader(ExShader* shader);
    ExShader* createShader(ExMaterial* mat, ExShader::ShaderType type, ParamList &params);
	protected:
	};

};	//end namespace

#endif
