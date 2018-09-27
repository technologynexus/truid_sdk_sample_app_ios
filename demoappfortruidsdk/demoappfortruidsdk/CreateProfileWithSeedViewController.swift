//
//  CreateProfileWithSeedViewController.swift
//  demoappfortruidsdk
//
//  Created by vijay nexus on 5/11/17.
//  Copyright © 2017 nexusgroup. All rights reserved.
//

import UIKit

class CreateProfileWithSeedViewController: UIViewController, UITextFieldDelegate,TSDKDelegateDskpp {

    @IBOutlet weak var seed: UITextField!
    
    @IBOutlet weak var profileName: UITextField!
    
    @IBOutlet weak var forSynchronized: UISwitch!
    
    @IBOutlet weak var forChallenge: UISwitch!
    
    @IBOutlet weak var usermsg: UITextView!
   
    
    let cancelToken = TSDKCancelToken()
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
        self.seed.delegate = self
        self.profileName.delegate = self
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        self.view.endEditing(true)
    }

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

    
    @IBAction func syncButtonChanged(_ sender: UISwitch) {
        
        if(sender.isOn){
            
            if(forChallenge.isOn){
                
                forChallenge.setOn(false, animated: true)
            }
        }
    }
    
    
    @IBAction func challengeButtonChanged(_ sender: UISwitch) {
        
        if(sender.isOn){
            
            if(forSynchronized.isOn){
                
                forSynchronized.setOn(false, animated: true)
            }
        }
    }
    
    
    @IBAction func nextClicked(_ sender: Any) {
        
        let name = profileName.text
        let seedText = seed.text
        
        if(forSynchronized.isOn == false && forChallenge.isOn == false){
            
            print("select profile type either synchronized or challenge")
            usermsg.text = "select profile type either synchronized or challenge"
            return
        }
        
        if(name?.lengthOfBytes(using: .utf8) == 0 || seedText?.lengthOfBytes(using: .utf8) == 0){
            
            print("enter profile name and seed")
            
            usermsg.text = "enter profile name and seed"
            return
        }
        
        let reqBuilder = TSDKActivationRequestBuilder()
        reqBuilder?.profileName = name
        reqBuilder?.seed = seedText
        if(forSynchronized.isOn){
            reqBuilder?.profileType = Synchronized
        }
        else{
            reqBuilder?.profileType = Challenge
        }
        var request:TSDKActivationRequest? = nil
        
        do{
            try ObjC.catchException
            {
                request = reqBuilder?.build()
                TSDKProfileManager.activateProfile(request, dskppDelegator: self, cancelToken: self.cancelToken)
            }
        }
        catch{
            
            if((error as NSError).userInfo.count > 0)
            {
                let missingField = (error as NSError).userInfo["nsmutableset"] as! NSArray
                
                if ((missingField.count) > 0){
                    
                    for field in missingField{
                        let intvalue = (field as! NSNumber).intValue
                        switch intvalue {
                        case FIELD.ACTIVATION_CODE.rawValue:
                            self.usermsg.text = "Invalid activation code"
                            break
                        case FIELD.SEED.rawValue:
                            print("invalid seed boom")
                            self.usermsg.text = "Invalid seed length. correct seed example : hhhhh-kkkkk-ppppp-eeeee"
                            break
                        default:
                            self.usermsg.text = "profile activation failed"
                            break
                        }
                    }
                }
            }
            else
            {
                self.usermsg.text = (error as NSError).domain
            }
            return
        }
        
        print("profile created")
    }
    
    @IBAction func cancelClicked(_ sender: Any) {
        
        self.navigationController?.popViewController(animated: true)
        
    }
    
    func onComplete(_ profile: TSDKProfile!) {
        
        print("profile activated")
        print(profile.getName())
        
        self.navigationController?.popToRootViewController(animated: true)
    }
    
    func startProgress() {
        
    }
    
    func stopProgressWithError(_ errorString: String!, error id: TSDKErrorId, errno num: Int32) {
        print("profile activation failed")
        print(errorString)
        
        switch id {
        case TSDK_INTERNAL:
            usermsg.text = "Error occured"
            break
        case TSDK_HTTP:
            usermsg.text = "communication error"
            break
        default:
            usermsg.text = "some error occured"
            break
        }
    }
    
    func startNetworking() {
        print("activation begin")
    }
    
    func stopNetworking() {
        print("activation end")
    }
}
