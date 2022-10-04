/**
 * Autogenerated by Thrift Compiler (0.17.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef save_H
#define save_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "save_types.h"

namespace save_service {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class saveIf {
 public:
  virtual ~saveIf() {}
  virtual int32_t save_data(const std::string& username, const std::string& passwd, const int32_t player1_id, const int32_t player2_id) = 0;
};

class saveIfFactory {
 public:
  typedef saveIf Handler;

  virtual ~saveIfFactory() {}

  virtual saveIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(saveIf* /* handler */) = 0;
  };

class saveIfSingletonFactory : virtual public saveIfFactory {
 public:
  saveIfSingletonFactory(const ::std::shared_ptr<saveIf>& iface) : iface_(iface) {}
  virtual ~saveIfSingletonFactory() {}

  virtual saveIf* getHandler(const ::apache::thrift::TConnectionInfo&) override {
    return iface_.get();
  }
  virtual void releaseHandler(saveIf* /* handler */) override {}

 protected:
  ::std::shared_ptr<saveIf> iface_;
};

class saveNull : virtual public saveIf {
 public:
  virtual ~saveNull() {}
  int32_t save_data(const std::string& /* username */, const std::string& /* passwd */, const int32_t /* player1_id */, const int32_t /* player2_id */) override {
    int32_t _return = 0;
    return _return;
  }
};

typedef struct _save_save_data_args__isset {
  _save_save_data_args__isset() : username(false), passwd(false), player1_id(false), player2_id(false) {}
  bool username :1;
  bool passwd :1;
  bool player1_id :1;
  bool player2_id :1;
} _save_save_data_args__isset;

class save_save_data_args {
 public:

  save_save_data_args(const save_save_data_args&);
  save_save_data_args& operator=(const save_save_data_args&);
  save_save_data_args() noexcept
                      : username(),
                        passwd(),
                        player1_id(0),
                        player2_id(0) {
  }

  virtual ~save_save_data_args() noexcept;
  std::string username;
  std::string passwd;
  int32_t player1_id;
  int32_t player2_id;

  _save_save_data_args__isset __isset;

  void __set_username(const std::string& val);

  void __set_passwd(const std::string& val);

  void __set_player1_id(const int32_t val);

  void __set_player2_id(const int32_t val);

  bool operator == (const save_save_data_args & rhs) const
  {
    if (!(username == rhs.username))
      return false;
    if (!(passwd == rhs.passwd))
      return false;
    if (!(player1_id == rhs.player1_id))
      return false;
    if (!(player2_id == rhs.player2_id))
      return false;
    return true;
  }
  bool operator != (const save_save_data_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const save_save_data_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class save_save_data_pargs {
 public:


  virtual ~save_save_data_pargs() noexcept;
  const std::string* username;
  const std::string* passwd;
  const int32_t* player1_id;
  const int32_t* player2_id;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _save_save_data_result__isset {
  _save_save_data_result__isset() : success(false) {}
  bool success :1;
} _save_save_data_result__isset;

class save_save_data_result {
 public:

  save_save_data_result(const save_save_data_result&) noexcept;
  save_save_data_result& operator=(const save_save_data_result&) noexcept;
  save_save_data_result() noexcept
                        : success(0) {
  }

  virtual ~save_save_data_result() noexcept;
  int32_t success;

  _save_save_data_result__isset __isset;

  void __set_success(const int32_t val);

  bool operator == (const save_save_data_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const save_save_data_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const save_save_data_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _save_save_data_presult__isset {
  _save_save_data_presult__isset() : success(false) {}
  bool success :1;
} _save_save_data_presult__isset;

class save_save_data_presult {
 public:


  virtual ~save_save_data_presult() noexcept;
  int32_t* success;

  _save_save_data_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class saveClient : virtual public saveIf {
 public:
  saveClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  saveClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  int32_t save_data(const std::string& username, const std::string& passwd, const int32_t player1_id, const int32_t player2_id) override;
  void send_save_data(const std::string& username, const std::string& passwd, const int32_t player1_id, const int32_t player2_id);
  int32_t recv_save_data();
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class saveProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::std::shared_ptr<saveIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext) override;
 private:
  typedef  void (saveProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_save_data(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  saveProcessor(::std::shared_ptr<saveIf> iface) :
    iface_(iface) {
    processMap_["save_data"] = &saveProcessor::process_save_data;
  }

  virtual ~saveProcessor() {}
};

class saveProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  saveProcessorFactory(const ::std::shared_ptr< saveIfFactory >& handlerFactory) noexcept :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo) override;

 protected:
  ::std::shared_ptr< saveIfFactory > handlerFactory_;
};

class saveMultiface : virtual public saveIf {
 public:
  saveMultiface(std::vector<std::shared_ptr<saveIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~saveMultiface() {}
 protected:
  std::vector<std::shared_ptr<saveIf> > ifaces_;
  saveMultiface() {}
  void add(::std::shared_ptr<saveIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  int32_t save_data(const std::string& username, const std::string& passwd, const int32_t player1_id, const int32_t player2_id) override {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->save_data(username, passwd, player1_id, player2_id);
    }
    return ifaces_[i]->save_data(username, passwd, player1_id, player2_id);
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class saveConcurrentClient : virtual public saveIf {
 public:
  saveConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr< ::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(prot);
  }
  saveConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr< ::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  int32_t save_data(const std::string& username, const std::string& passwd, const int32_t player1_id, const int32_t player2_id) override;
  int32_t send_save_data(const std::string& username, const std::string& passwd, const int32_t player1_id, const int32_t player2_id);
  int32_t recv_save_data(const int32_t seqid);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  std::shared_ptr< ::apache::thrift::async::TConcurrentClientSyncInfo> sync_;
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif

} // namespace

#endif
