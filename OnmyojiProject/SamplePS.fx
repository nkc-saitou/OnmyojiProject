// ピクセルシェーダーの入力
struct PS_INPUT
{
	float4 DiffuseColor       : COLOR0;
	float4 SpecularColor      : COLOR1;
	float2 TextureCoord0      : TEXCOORD0;
	float2 TextureCoord1      : TEXCOORD1;
};

// ピクセルシェーダーの出力
struct PS_OUTPUT
{
	float4 Output             : COLOR0;
};

// 描画するテクスチャ
sampler Texture : register(s0);

//タイマー(外部から
float timer : register(c0);

PS_OUTPUT main(PS_INPUT PSInput)
{
	PS_OUTPUT PSOutput;
	float4 TextureColor;
	float2 CalcPos;

	CalcPos.x = fmod(1.0 + PSInput.TextureCoord0.x + 0.002*sin(PSInput.TextureCoord0.y * 50.0 + timer), 1.0);
	CalcPos.y = PSInput.TextureCoord0.y;

	TextureColor = tex2D(Texture, CalcPos);
	PSOutput.Output = TextureColor;
	return PSOutput;
}