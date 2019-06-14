Lab 1. Out Of The Box

  - Create an IDL file, then generate code
  - In the publisher code, give the sample some values, just so they are not empty

Lab 2. Deadline QoS

  - Adjust the DR QoS to add a .5s deadline (don't change DW yet)
  - Discuss why this does not work (QoS mismatch)
  - Fix the DW QoS and rerun, showing that data now flows
  - Note that we are actually not sending within the deadline period... add listener

Lab 3. Reporting A QoS Mismatch

  - In the publisher code, add a listener to report on Offered QoS incompatability
  - Set the DW deadline period to be 1.5s to cause a QoS mismatch
    - look up DDS_QosPolicyId_t in the docs and discuss

Lab 4. Load user type into Admin Console

  - set DR and DW deadline periods to 1.5s to eliminate match errors
  - create XML type representation and load into Admin Console
  - open the tool and note how all DWs are writing to the same instance
    - but it doesn't work! (change the type name in quickstartApplication.c)

Lab 5. Switch to a keyed type, and define topic name in IDL

  - modify the IDL to add //@key to the "id" member
  - add a constant for the topic name
  - call rtiddsgen again to impose the change (remember: "update", not "create")
  - modify pub and sub code to use this constant

Lab 6. Ownership

  - use admin console to view that different instances are being recognized
  - add exclusive ownership and ownership (different students use different
    strengths. Keyed "id" value should be set to the same )

Lab 7. Waitsets

  - modify the subscriber code to use a waitset to be notified of data
  - "recycle" the listener callback and call it when the WaitSet returns with
    data.
  - don't forget to remove the on_data_available listener code


BONUS LABS

Lab - FlatData

  - create a fresh user project using the flatdata idl
    - $RTIMEHOME/rtiddsgen/scripts/rtiddsgen -micro -language C++ -create typefiles -create examplefiles -create makefiles ./quickstart.idl 
    - on the publisher, modify the writer code to get offsets and set sample values
    - on the subscriber, modify the DR listener to get offsets and print a couple sample values
    

