#include <vector>
#include <openssl/evp.h>

void CryptoInitialize();
void CryptoTest();
bool AesEncryptForSend(const unsigned char* msg, size_t msg_len,
    std::vector<unsigned char>* encrypted_msg, size_t* encrypted_msg_len);
bool AesDecryptForRecieve(const unsigned char* msg, size_t msg_len,
    std::vector<unsigned char>* decrypted_msg, size_t* decrypted_msg_len);
bool AesEncryptForSendEx(const unsigned char* msg, size_t msg_len,
    std::vector<unsigned char>* encrypted_msg, size_t* encrypted_msg_len);
bool AesDecryptForRecieveEx(const unsigned char* msg, size_t msg_len,
    std::vector<unsigned char>* decrypted_msg, size_t* decrypted_msg_len);
bool LoadAesKeyFromFile(const std::string& filename, unsigned char* key, size_t keyLength);
bool SaveAesKeyToFile(const std::string& filename, const unsigned char* key, size_t keyLength);
EVP_PKEY* GetRsaKey(std::string& pubkey);
void GetAesKey(unsigned char* aes_key, size_t aes_key_len, std::string filename = "");
bool GenerateAesKey(unsigned char* aes_key, size_t aes_key_len);
bool GetEncodedPublicKey(std::string& encoded_pub_key);
bool GenerateEncryptedKeyData(std::string recieved_pub_key,
    const unsigned int call_status,
    unsigned char* encrypted_key_data,
    size_t* encrypted_key_data_size);
bool ParsingEncryptedKeyData(unsigned int& call_status,
    unsigned char* encrypted_key_data,
    size_t encrypted_key_data_size);
void RsaEncryptWithKey(const unsigned char* msg, size_t msg_len,
    unsigned char* encrypted_msg, size_t* encrypted_msg_len);
void RsaEncryptWithRecievedKey(const unsigned char* msg, size_t msg_len,
    unsigned char* encrypted_msg, size_t* encrypted_msg_len);
bool RsaDecryptWithKey(const unsigned char* msg, size_t msg_len,
    unsigned char* decrypted_msg, size_t* decrypted_msg_len);
bool SetRecievedRsaPublicKey(std::string publickey);
std::string Base64Decode(const std::string& encoded);
std::string Base64Encode(const std::string& encoded);
bool InitializeAesKey(void);
