// dllmain.h : Declaration of module class.

class CAnvizOcxModule : public CAtlDllModuleT< CAnvizOcxModule >
{
public :
	DECLARE_LIBID(LIBID_AnvizOcxLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ANVIZOCX, "{1F732A3C-DB73-4CD7-ADCB-A451BAC9190C}")
};

extern class CAnvizOcxModule _AtlModule;
