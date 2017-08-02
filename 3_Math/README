Level	Precedence group	Operator	Description			Grouping
1	Scope			::		scope qualifier			Left-to-right
2	Postfix (unary)		++ 		postfix increment
				--		postfix decrement		
				()		functional forms
				[]		subscript
				. ->		member access
3	Prefix (unary)		++ 		prefix increment		Right-to-left
				--		prefix decrement
				~ !		bitwise NOT / logical NOT
				+ -		unary prefix
				& *		reference / dereference
				new delete	allocation / deallocation
				sizeof		parameter pack
				(type)		C-style type-casting
4	Pointer-to-member	.* ->*		access pointer			Left-to-right
5	Arithmetic: scaling	* / %		multiply, divide, modulo	
6	Arithmetic: addition	+ -		addition, subtraction			
7	Bitwise shift		<< >>		shift left, shift right			
8	Relational		< > <= >=	comparison operators			
9	Equality		== !=		equality / inequality			
10	And			&		bitwise AND			
11	Exclusive or		^		bitwise XOR				
12	Inclusive or		|		bitwise OR				
13	Conjunction		&&		logical AND				
14	Disjunction		||		logical OR				
15	Assignment-level	= *= /= 	assignment  			Right-to-left
	expressions		%= += -=	compound assignment	
				>>= <<=
				&= ^= |=
				?:		conditional operator
16	Sequencing		,		comma separator			Left-to-right
-----------------------------------------------------------------------------------------------------------
Group				Type names*			Notes on size / precision
Character types			char				Exactly one byte in size. At least 8 bits.
				char16_t			Not smaller than char. At least 16 bits.
				char32_t			Not smaller than char16_t. At least 32 bits.
				wchar_t				Can represent the largest supported character set.
Integer types (signed)		signed char			Same size as char. At least 8 bits.
				(signed) short (int)		Not smaller than char. At least 16 bits.
				(signed) int			Not smaller than short. At least 16 bits.
				(signed) long (int)		Not smaller than int. At least 32 bits.
				(signed) long long (int)	Not smaller than long. At least 64 bits.
Integer types (unsigned)	unsigned char			(same size as their signed counterparts)
				unsigned short (int)
				unsigned int
				unsigned long (int)
				unsigned long long (int)
Floating-point types		float	
				double				Precision not less than float
				long double			Precision not less than double
Boolean type			bool	
Void type			void	no storage
Null pointer			decltype(nullptr)	
