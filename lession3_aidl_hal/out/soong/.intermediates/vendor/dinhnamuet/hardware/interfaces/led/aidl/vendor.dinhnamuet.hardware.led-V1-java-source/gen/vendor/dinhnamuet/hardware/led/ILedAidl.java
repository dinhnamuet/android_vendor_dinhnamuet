/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package vendor.dinhnamuet.hardware.led;
public interface ILedAidl extends android.os.IInterface
{
  /**
   * The version of this interface that the caller is built against.
   * This might be different from what {@link #getInterfaceVersion()
   * getInterfaceVersion} returns as that is the version of the interface
   * that the remote object is implementing.
   */
  public static final int VERSION = 1;
  public static final String HASH = "notfrozen";
  /** Default implementation for ILedAidl. */
  public static class Default implements vendor.dinhnamuet.hardware.led.ILedAidl
  {
    @Override public void setLed(byte index, byte value) throws android.os.RemoteException
    {
    }
    @Override public byte getLed(byte index) throws android.os.RemoteException
    {
      return 0;
    }
    @Override
    public int getInterfaceVersion() {
      return 0;
    }
    @Override
    public String getInterfaceHash() {
      return "";
    }
    @Override
    public android.os.IBinder asBinder() {
      return null;
    }
  }
  /** Local-side IPC implementation stub class. */
  public static abstract class Stub extends android.os.Binder implements vendor.dinhnamuet.hardware.led.ILedAidl
  {
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.markVintfStability();
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an vendor.dinhnamuet.hardware.led.ILedAidl interface,
     * generating a proxy if needed.
     */
    public static vendor.dinhnamuet.hardware.led.ILedAidl asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof vendor.dinhnamuet.hardware.led.ILedAidl))) {
        return ((vendor.dinhnamuet.hardware.led.ILedAidl)iin);
      }
      return new vendor.dinhnamuet.hardware.led.ILedAidl.Stub.Proxy(obj);
    }
    @Override public android.os.IBinder asBinder()
    {
      return this;
    }
    @Override public boolean onTransact(int code, android.os.Parcel data, android.os.Parcel reply, int flags) throws android.os.RemoteException
    {
      java.lang.String descriptor = DESCRIPTOR;
      if (code >= android.os.IBinder.FIRST_CALL_TRANSACTION && code <= android.os.IBinder.LAST_CALL_TRANSACTION) {
        data.enforceInterface(descriptor);
      }
      switch (code)
      {
        case INTERFACE_TRANSACTION:
        {
          reply.writeString(descriptor);
          return true;
        }
        case TRANSACTION_getInterfaceVersion:
        {
          reply.writeNoException();
          reply.writeInt(getInterfaceVersion());
          return true;
        }
        case TRANSACTION_getInterfaceHash:
        {
          reply.writeNoException();
          reply.writeString(getInterfaceHash());
          return true;
        }
      }
      switch (code)
      {
        case TRANSACTION_setLed:
        {
          byte _arg0;
          _arg0 = data.readByte();
          byte _arg1;
          _arg1 = data.readByte();
          data.enforceNoDataAvail();
          this.setLed(_arg0, _arg1);
          reply.writeNoException();
          break;
        }
        case TRANSACTION_getLed:
        {
          byte _arg0;
          _arg0 = data.readByte();
          data.enforceNoDataAvail();
          byte _result = this.getLed(_arg0);
          reply.writeNoException();
          reply.writeByte(_result);
          break;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
      return true;
    }
    private static class Proxy implements vendor.dinhnamuet.hardware.led.ILedAidl
    {
      private android.os.IBinder mRemote;
      Proxy(android.os.IBinder remote)
      {
        mRemote = remote;
      }
      private int mCachedVersion = -1;
      private String mCachedHash = "-1";
      @Override public android.os.IBinder asBinder()
      {
        return mRemote;
      }
      public java.lang.String getInterfaceDescriptor()
      {
        return DESCRIPTOR;
      }
      @Override public void setLed(byte index, byte value) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeByte(index);
          _data.writeByte(value);
          boolean _status = mRemote.transact(Stub.TRANSACTION_setLed, _data, _reply, 0);
          if (!_status) {
            throw new android.os.RemoteException("Method setLed is unimplemented.");
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public byte getLed(byte index) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        byte _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeByte(index);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getLed, _data, _reply, 0);
          if (!_status) {
            throw new android.os.RemoteException("Method getLed is unimplemented.");
          }
          _reply.readException();
          _result = _reply.readByte();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override
      public int getInterfaceVersion() throws android.os.RemoteException {
        if (mCachedVersion == -1) {
          android.os.Parcel data = android.os.Parcel.obtain();
          android.os.Parcel reply = android.os.Parcel.obtain();
          try {
            data.writeInterfaceToken(DESCRIPTOR);
            boolean _status = mRemote.transact(Stub.TRANSACTION_getInterfaceVersion, data, reply, 0);
            reply.readException();
            mCachedVersion = reply.readInt();
          } finally {
            reply.recycle();
            data.recycle();
          }
        }
        return mCachedVersion;
      }
      @Override
      public synchronized String getInterfaceHash() throws android.os.RemoteException {
        if ("-1".equals(mCachedHash)) {
          android.os.Parcel data = android.os.Parcel.obtain();
          android.os.Parcel reply = android.os.Parcel.obtain();
          try {
            data.writeInterfaceToken(DESCRIPTOR);
            boolean _status = mRemote.transact(Stub.TRANSACTION_getInterfaceHash, data, reply, 0);
            reply.readException();
            mCachedHash = reply.readString();
          } finally {
            reply.recycle();
            data.recycle();
          }
        }
        return mCachedHash;
      }
    }
    static final int TRANSACTION_setLed = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_getLed = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_getInterfaceVersion = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777214);
    static final int TRANSACTION_getInterfaceHash = (android.os.IBinder.FIRST_CALL_TRANSACTION + 16777213);
  }
  public static final java.lang.String DESCRIPTOR = "vendor$dinhnamuet$hardware$led$ILedAidl".replace('$', '.');
  public void setLed(byte index, byte value) throws android.os.RemoteException;
  public byte getLed(byte index) throws android.os.RemoteException;
  public int getInterfaceVersion() throws android.os.RemoteException;
  public String getInterfaceHash() throws android.os.RemoteException;
}
