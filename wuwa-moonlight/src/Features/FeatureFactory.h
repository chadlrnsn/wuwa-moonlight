#pragma once
#include <memory>
#include <functional>
#include <string>

class IFeatureFactory {
public:
    virtual ~IFeatureFactory() = default;
    
    virtual void Render() = 0;
    virtual void Draw() = 0;
    virtual void Run() = 0;
    virtual void CallOrigin() = 0;
    virtual void RenderDebug() = 0;
    virtual bool IsEnable() = 0;
    
    // Factory method to create instances
    template<typename T, typename... Args>
    static std::shared_ptr<T> Create(Args&&... args) {
        static_assert(std::is_base_of_v<IFeatureFactory, T>, "T must derive from IFeatureFactory");
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
};

class FeatureFactory : public IFeatureFactory {
protected:
    bool bEnable{ false };
    bool bOnce{ false };
    
public:
    FeatureFactory() = default;
    ~FeatureFactory() override = default;
    
    void Render() override {
        // Basic implementation
    }

    void RenderDebug() override {
        // Basic implementation
    }
    
    void Draw() override {
        // Basic implementation
    }
    
    void Run() override {
        // Basic implementation
    }
    
    void CallOrigin() override {
        // Basic implementation
    }

    bool IsEnable() override {
        return bEnable;
    }
};

// Example of a custom factory implementation
class CustomFeature : public FeatureFactory {
private:
    std::string m_name;
    int m_id{0};

public:
    CustomFeature(std::string name, int id) : m_name(std::move(name)), m_id(id) {}
    
    void Render() override {
        // Custom rendering logic
        FeatureFactory::Render(); // Call base implementation if needed
    }
    
    void Draw() override {
        // Custom drawing logic
        FeatureFactory::Draw(); // Call base implementation if needed
    }
    
    // Custom methods
    constexpr int GetID() const noexcept { return m_id; }
    const std::string& GetName() const noexcept { return m_name; }
};

/*
// Example usage:
auto factory = ICFactory::Create<CustomFactory>("MyFeature", 42);
factory->Render();
factory->Draw();
int id = factory->GetID(); // Access custom methods
*/