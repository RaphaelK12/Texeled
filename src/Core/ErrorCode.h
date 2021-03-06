#ifndef __CORE_ERROR_CODE_H__
#define __CORE_ERROR_CODE_H__

class ErrorCode
{
	friend class StaticResolver;
	class StaticResolver
	{
	public:
		StaticResolver();
	};
public:
	static ErrorCode	Ok;
	static ErrorCode	Fail;
	static ErrorCode	NotImplemented;
	static ErrorCode	InvalidArgument;
public:
						ErrorCode(int iCode, const char* pMessage, ...);
						ErrorCode(const ErrorCode& oRight);
						~ErrorCode();

	bool				operator==(ErrorCode& oRight);
	bool				operator!=(ErrorCode& oRight);
	void				operator=(const ErrorCode& oRight);

	int					GetCode() const { return m_iCode; }
	const char*			ToString() const { return m_pMessage; }
protected:
	void				Release();
protected:
	mutable bool		m_bChecked;
	int					m_iCode;
	char*				m_pMessage;
	bool				m_bStatic;

	static bool			s_bStaticTime;
	static StaticResolver	s_oStaticResolver;
};


#endif //__CORE_ERROR_CODE_H__