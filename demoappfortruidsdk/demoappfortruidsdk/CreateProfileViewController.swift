//
//  CreateProfileControllerViewController.swift
//  demoappfortruidsdk
//
//  Created by vijay nexus on 5/11/17.
//  Copyright © 2017 nexusgroup. All rights reserved.
//

import UIKit

class CreateProfileViewController: UIViewController, UITextFieldDelegate, TSDKDelegateDskpp {
    @IBOutlet weak var usermsg: UITextView!

    @IBOutlet weak var activationAddress: UITextField!
    
    @IBOutlet weak var network: UIActivityIndicatorView!
    @IBOutlet weak var advancedButton: UIButton!
    @IBOutlet weak var nextButton: UIButton!
    
    let cancelToken = TSDKCancelToken()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.activationAddress.delegate = self

        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        
        self.view.endEditing(true)
        usermsg.text = ""
    }

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */
    @IBAction func nextClicked(_ sender: Any) {
        
        let activationUrl = activationAddress.text
        if((activationUrl?.lengthOfBytes(using: .utf8))! == 0 ||  (activationUrl?.contains(" "))!){
            
            print("invalid url")
            usermsg.text = "Invalid activation address"
        }
        
        let reqBuilder = TSDKActivationRequestBuilder()
        reqBuilder?.link = activationUrl
        
        var request:TSDKActivationRequest? = nil
        
        do{
            try ObjC.catchException
            {
                request = reqBuilder?.build()
                self.network.startAnimating()
                self.usermsg.text = "Please wait"
                self.nextButton.isEnabled = false
                self.advancedButton.isEnabled = false
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
                        case FIELD.INVALID_URL.rawValue:
                            print("invalid url")
                            self.usermsg.text = "invalid url"
                            break
                        default:
                            self.usermsg.text = "profile activation failed"
                            break
                        }
                    }
                }
            }
            return
        }
    }

    @IBAction func advancedClicked(_ sender: Any) {
        
        
        let viewController = storyboard?.instantiateViewController(withIdentifier: "CreateProfileWithSeed")
        
        
        self.navigationController?.pushViewController(viewController!, animated: true)
        
//        self.present(viewController!, animated: true, completion: {
//        
//        print("create profile with seed")
//        })
        
        
    }
    
    func startProgress() {
        
        print("start")
    }
    func stopNetworking() {
        print("stop networking network indicator")
    }
    func stopProgressWithError(_ errorString: String!, error id: TSDKErrorId, errno num: Int32) {
        
        print("stop with error")
        usermsg.text = errorString + " Failed"
        print("TSDKErrorID \(id)")
        network.stopAnimating()
        
        self.nextButton.isEnabled = true
        self.advancedButton.isEnabled = true
    }
    func onComplete(_ profile: TSDKProfile!) {
        
        self.nextButton.isEnabled = true
        self.advancedButton.isEnabled = true
        
        print("onComplete ..profile create!")
        activationAddress.text = ""
        usermsg.text = "success!"
        
        network.stopAnimating()
    }
    func startNetworking() {
        print("start network indicator")
    }
}
